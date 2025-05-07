// Renard Kombo
///////////////////////////// LAB 4 PART 1: Symmetric Tree /////////////////////////////////////////////////
// 5/6/2025

bool isMirrorTree(struct TreeNode* leftSubtreeRoot, struct TreeNode* rightSubtreeRoot) {
    if (leftSubtreeRoot == NULL && rightSubtreeRoot == NULL) return true;
    if (leftSubtreeRoot == NULL || rightSubtreeRoot == NULL) return false;
    return (leftSubtreeRoot->val == rightSubtreeRoot->val)
        && isMirrorTree(leftSubtreeRoot->left, rightSubtreeRoot->right)
        && isMirrorTree(leftSubtreeRoot->right, rightSubtreeRoot->left);
}

bool isSymmetric(struct TreeNode* rootNode) {
    if (rootNode == NULL) return true;
    return isMirrorTree(rootNode->left, rootNode->right);
}



//////////////////////////// LAB 4 PART 2: Number of Islands ////////////////////////////////

void dfs(char** grid, int rows, int cols, int r, int c) {
    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != '1') return;

    grid[r][c] = '0'; // Mark as visited

    dfs(grid, rows, cols, r - 1, c); // up
    dfs(grid, rows, cols, r + 1, c); // down
    dfs(grid, rows, cols, r, c - 1); // left
    dfs(grid, rows, cols, r, c + 1); // right
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) return 0;

    int cnt = 0;
    int col = gridColSize[0];

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == '1') {
                cnt++;
                dfs(grid, gridSize, col, i, j);
            }
        }
    }

    return cnt;
}
