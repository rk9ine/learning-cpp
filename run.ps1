param(
    [Parameter(Mandatory = $true)][string]$Day,
    [switch]$Rep
)

$root = $PSScriptRoot
$dir  = Join-Path $root $Day
$src  = Join-Path $dir "main.cpp"

if (-not (Test-Path $dir)) { Write-Host "No such day: $Day" -ForegroundColor Red; exit 1 }

if ($Rep) {
    $skel = Join-Path $dir "skeleton.cpp"
    if (-not (Test-Path $skel)) { Write-Host "No skeleton.cpp in $Day" -ForegroundColor Red; exit 1 }
    Copy-Item $skel $src -Force
    Write-Host "main.cpp reset to blank skeleton. Write it from memory." -ForegroundColor Yellow
    exit 0
}

$exe = Join-Path $dir "app.exe"
if (Test-Path $exe) { Remove-Item $exe -Force; Write-Host "--- deleted old build ---" -ForegroundColor DarkGray }
Write-Host "--- compiling ---" -ForegroundColor DarkGray
g++ -std=c++23 -Wall -Wextra -Wpedantic $src -o $exe
if ($LASTEXITCODE -ne 0) { Write-Host "--- compile FAILED ---" -ForegroundColor Red; exit 1 }

Write-Host "--- running ---" -ForegroundColor DarkGray
& $exe
Write-Host "--- exit code: $LASTEXITCODE ---" -ForegroundColor DarkGray
