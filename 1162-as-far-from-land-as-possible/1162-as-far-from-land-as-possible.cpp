class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // Get the size of the grid
        int n = grid.size();
        
        // Initialize the distance and size variables
        int dist=0, size;
        
        // Create a queue to store the cells to be processed
        queue<pair<int, int>> q;
        
        // Array to store the row and column shifts for the four directions
        int drow[] = {0, -1, 0, 1}, dcol[] = {-1, 0, 1, 0};
        
        // Start the BFS from all the cells that have the value 1
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)    
                if(grid[i][j] == 1)
                    q.push({i, j});
        
        // If all cells are 1's, return -1
        if(q.size() == n*n)
            return -1;
        
        // Continue the BFS until all cells have been processed
        while(!q.empty()){
            // Get the number of cells to be processed in this round
            size = q.size();
            
            // Increase the distance
            dist++;
            
            // Process all the cells in the current round
            while(size--){
                // Get the row and column of the current cell
                int r = q.front().first, c = q.front().second;
                
                // Remove the current cell from the queue
                q.pop();
                
                // Process all the four directions
                for(int i=0;i<4;i++){
                    // Get the row and column of the next cell
                    int nrow = r + drow[i], ncol = c + dcol[i];
                    
                    // Check if the next cell is within the grid and has a value 0
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==0){
                        // Update the value of the next cell
                        grid[nrow][ncol] = 1;
                        
                        // Add the next cell to the queue for the next round
                        q.push({nrow, ncol});
                    } 
                }
            }
        }
        
        // Return the final distance
        return dist-1;
    }
};