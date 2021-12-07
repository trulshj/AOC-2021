
data ← ⍎¨','(≠⊆⊢)⊃⊃⎕NGET'input07.txt' 1

part1 ← {+/|⍵-⍵[⍋⍵][(≢⍵)÷2]}
part2 ← {+/2!1+¨|⍵-⌊0.5+(+⌿⍵)÷≢⍵}

part1 data
part2 data
