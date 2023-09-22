,          ; Read the first digit into cell 0
- '0' ,    ; Subtract ASCII '0' to get the actual digit value
,          ; Read the second digit into cell 1
- '0'      ; Subtract ASCII '0' to get the actual digit value

[          ; Start of loop to multiply the two digits
    >      ; Move to cell 1
    [      ; Start of inner loop
        -  ; Subtract 1 from cell 1
        <  ; Move to cell 0
        +  ; Add 1 to cell 0
    ]      ; End of inner loop
    > -    ; Subtract 1 from cell 1 and move back to cell 0
]          ; End of outer loop

.          ; Print the result as a character

