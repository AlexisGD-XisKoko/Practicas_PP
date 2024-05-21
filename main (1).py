# Alexis Guzman Dolores 20/04/24 Paradigmas de Programacion- Robot 

class Robot:
    def __init__(self, grid):
        self.grid = grid
        self.rows = len(grid)
        self.cols = len(grid[0])
        self.path = []
        self.visited = [[False for _ in range(self.cols)] for _ in range(self.rows)]

    def is_valid(self, x, y):
        return 0 <= x < self.rows and 0 <= y < self.cols and not self.grid[x][y] and not self.visited[x][y]

    def find_path(self):
        if self.dfs(0, 0):
            return self.path
        else:
            return []

    def dfs(self, x, y):
        if x == self.rows - 1 and y == self.cols - 1:
            self.path.append((x, y))
            return True

        if self.is_valid(x, y):
            self.visited[x][y] = True
            self.path.append((x, y))

            # Move right
            if self.dfs(x, y + 1):
                return True

            # Move down
            if self.dfs(x + 1, y):
                return True

            # If neither move works, backtrack
            self.path.pop()
            self.visited[x][y] = False

        return False

# Ejemplo de uso:
grid = [
    [0, 0, 1, 1],
    [1, 0, 1, 0],
    [1, 0, 0, 1],
    [1, 1, 0, 0]
]

robot = Robot(grid)
path = robot.find_path()

if path:
    print("Path found:")
    for step in path:
        print(f"({step[0]}, {step[1]})")
else:
    print("No path found")
