# Not a super difficult problem, but the trick is knowing how to find the indices for the box array.
# That can be simply handled using floor division by 3, which will return the indices in range 0-2, with
# the top-left box as [0, 0]
# Also, this method uses list comprehensions which is very Pythonic.

def isValidSudoku(board: list[list[str]]) -> bool:
    box = [[[] for _ in range(3)] for _ in range(3)]
    row = [[] for _ in range(9)]
    col = [[] for _ in range(9)]
    for r in range(9):
        for c in range(9):
            value = board[r][c]
            # print("ROW: ", r, "COL: ", c, "VALUE: ", value)
            if (value == '.'):
                continue
            if value in box[r//3][c//3]:
                return False
            if value in row[r]:
                return False
            if value in col[c]:
                return False
            else:
                box[r//3][c//3].append(value)
                row[r].append(value)
                col[c].append(value)
            # print(box)
            # print(row)
            # print(col)
    return True


test1 = validSudoku([["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]])

test2 = validSudoku([["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]])

print(test1)
print(test2)