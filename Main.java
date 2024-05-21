// Alexis Guzman Dolores 20/04/24 Paradigmas de Programacion- Robot 

import java.util.ArrayList;
import java.util.List;

class Robot {
    private int[][] grid;
    private int rows;
    private int cols;
    private boolean[][] visited;
    private List<int[]> path;

    public Robot(int[][] grid) {
        this.grid = grid;
        this.rows = grid.length;
        this.cols = grid[0].length;
        this.visited = new boolean[rows][cols];
        this.path = new ArrayList<>();
    }

    public boolean isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0 && !visited[x][y];
    }

    public List<int[]> findPath() {
        if (dfs(0, 0)) {
            return path;
        } else {
            return new ArrayList<>();
        }
    }

    private boolean dfs(int x, int y) {
        if (x == rows - 1 && y == cols - 1) {
            path.add(new int[]{x, y});
            return true;
        }

        if (isValid(x, y)) {
            visited[x][y] = true;
            path.add(new int[]{x, y});

            // Move right
            if (dfs(x, y + 1)) {
                return true;
            }

            // Move down
            if (dfs(x + 1, y)) {
                return true;
            }

            // If neither move works, backtrack
            path.remove(path.size() - 1);
            visited[x][y] = false;
        }

        return false;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] grid = {
            {0, 0, 1, 0},
            {0, 0, 0, 0},
            {1, 1, 0, 1},
            {0, 0, 0, 0}
        };

        Robot robot = new Robot(grid);
        List<int[]> path = robot.findPath();

        if (!path.isEmpty()) {
            System.out.println("Path found:");
            for (int[] step : path) {
                System.out.println("(" + step[0] + ", " + step[1] + ")");
            }
        } else {
            System.out.println("No path found");
        }
    }
}
