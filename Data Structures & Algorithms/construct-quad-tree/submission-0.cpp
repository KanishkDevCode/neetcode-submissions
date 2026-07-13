class Solution {
public:
    Node* build(vector<vector<int>>& grid, int row, int col, int size) {
        
        bool same = true;

        int value = grid[row][col];

        for(int i = row; i < row + size; i++)
        {
            for(int j = col; j < col + size; j++)
            {
                if(grid[i][j] != value)
                {
                    same = false;
                    break;
                }
            }

            if(!same)
                break;
        }

        if(same)
        {
            return new Node(value, true);
        }

        int half = size / 2;

        Node* root = new Node(true, false);

        root->topLeft = build(grid, row, col, half);
        root->topRight = build(grid, row, col + half, half);
        root->bottomLeft = build(grid, row + half, col, half);
        root->bottomRight = build(grid, row + half, col + half, half);

        return root;
    }

    Node* construct(vector<vector<int>>& grid)
    {
        return build(grid, 0, 0, grid.size());
    }
};