<#
.SYNOPSIS
  Compile and (optionally) run a command, play a "FAAAAH" sound on error.

USAGE
  .\run_with_sound.ps1 -Compile 'g++ "file.cpp" -o file.exe' -Run '.\file.exe'
  .\run_with_sound.ps1 -Compile 'g++ "file.cpp" -o file.exe'
#>

param(
    [Parameter(Mandatory=$true)][string]
    $Compile,

    [Parameter(Mandatory=$false)][string]
    $Run
)

function Play-Faah {
    # Try multiple playback methods for robustness
    try {
        Add-Type -AssemblyName System.Speech -ErrorAction Stop
        $synth = New-Object System.Speech.Synthesis.SpeechSynthesizer
        $synth.Speak('FAAAAH')
        return
    } catch {}

    try {
        $voice = New-Object -ComObject SAPI.SpVoice
        $voice.Speak('FAAAAH')
        return
    } catch {}

    try {
        [System.Media.SystemSounds]::Beep.Play()
        Start-Sleep -Milliseconds 150
        [System.Media.SystemSounds]::Asterisk.Play()
        return
    } catch {}

    # Final fallback: console beeps
    try {
        [console]::Beep(1000,200)
        Start-Sleep -Milliseconds 120
        [console]::Beep(700,350)
    } catch {}

    # Last-resort: generate a short WAV tone and play it via mshta (Audio tag)
    try {
        $wavPath = Join-Path $PSScriptRoot 'faah.wav'
        if (-not (Test-Path $wavPath)) {
            $sampleRate = 44100
            $duration = 0.6
            $numSamples = [int]($sampleRate * $duration)
            $frequency = 500
            $amplitude = 16000

            $ms = New-Object System.IO.MemoryStream
            $bw = New-Object System.IO.BinaryWriter($ms)
            $bw.Write([System.Text.Encoding]::ASCII.GetBytes('RIFF'))
            $bw.Write([int](36 + $numSamples * 2))
            $bw.Write([System.Text.Encoding]::ASCII.GetBytes('WAVE'))
            $bw.Write([System.Text.Encoding]::ASCII.GetBytes('fmt '))
            $bw.Write([int]16)
            $bw.Write([short]1)
            $bw.Write([short]1)
            $bw.Write([int]$sampleRate)
            $bw.Write([int]($sampleRate * 2))
            $bw.Write([short]2)
            $bw.Write([short]16)
            $bw.Write([System.Text.Encoding]::ASCII.GetBytes('data'))
            $bw.Write([int]($numSamples * 2))

            for ($i = 0; $i -lt $numSamples; $i++) {
                $t = $i / $sampleRate
                $val = [int]([math]::Round($amplitude * [math]::Sin(2 * [math]::PI * $frequency * $t)))
                $bw.Write([short]$val)
            }

            $bw.Flush()
            [System.IO.File]::WriteAllBytes($wavPath, $ms.ToArray())
            $bw.Close()
            $ms.Close()
        }

        $full = (Get-Item $wavPath).FullName -replace '\\','/'
        $uri = "file:///$full"
        $js = "javascript:var a=new Audio('$uri');a.play();setTimeout(function(){close();},700);"
        Start-Process mshta.exe $js | Out-Null
        return
    } catch {}
}

Write-Host "Compiling: $Compile"
try {
    Invoke-Expression $Compile
} catch {
    # Invoke-Expression may throw for malformed commands; ensure we still handle it
}

$code = $LASTEXITCODE
if ($code -ne 0) {
    Write-Host "Compile failed (exit code $code)." -ForegroundColor Red
    Play-Faah
    exit $code
}

if ($Run) {
    Write-Host "Running: $Run"
    try {
        Invoke-Expression $Run
    } catch {
    }
    $code = $LASTEXITCODE
    if ($code -ne 0) {
        Write-Host "Run failed (exit code $code)." -ForegroundColor Red
        Play-Faah
        exit $code
    }
}

Write-Host "Success." -ForegroundColor Green
