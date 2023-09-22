,          ; Read the first digit into cell 0
- '0' ,    ; Subtract ASCII '0' to get the actual digit value
,          ; Read the second digit into cell 1
- '0'      ; Subtract ASCII '0' to get the actual digit value

[          ; Start of loop to add the two digits
    > +    ; Add the value in cell 1 to cell 0
    < -    ; Subtract 1 from cell 1
]          ; End of loop

.          ; Print the result as a character
