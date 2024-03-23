param (
    [string]$path = 'Unknown',
    [int]$b = '0',
    [int]$v = '0',
    [int]$t = '0'
)

$path = "C:\Users\sluec\OneDrive\Documents\Code\Projects\FlightBookingSuggestor_v1"

build_generic.ps1 -path $path -b $b -v $v -t $t