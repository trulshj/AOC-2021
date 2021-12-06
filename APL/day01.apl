
data ← ⍎¨⊃⎕NGET 'input01.txt'1

part1 ← {+/2</⍵} ⍝ plus-reduce of pair-wise less than reduce
part2 ← {part1 3+/⍵} ⍝ turn input into sliding window data by 3-wise plus reduce

part1 data
part2 data
