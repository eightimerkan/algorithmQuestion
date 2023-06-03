#include <iostream>

void dfs(int **matrix, int **visited, int size, int row, int col, int value, int &groupSize)
{
    if (row < 0 || row >= size || col < 0 || col >= size)
        return;
    if (visited[row][col] == 1 || matrix[row][col] != value)
        return;
    visited[row][col] = 1;
    groupSize++;
    

    dfs(matrix, visited, size, row - 1, col, value, groupSize);
    dfs(matrix, visited, size, row + 1, col, value, groupSize);
    dfs(matrix, visited, size, row, col - 1, value, groupSize);
    dfs(matrix, visited, size, row, col + 1, value, groupSize);
}

void sameValueCells(int *matrix[], int size)
{
    int **visited = new int*[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = new int[size];
        for (int j = 0; j < size; j++)
            visited[i][j] = 0;
    }

    int groupCount = 0;
    int *groupSizes = new int[size * size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (visited[i][j] == 0)
            {
                int value = matrix[i][j];
                int groupSize = 0;
                dfs(matrix, visited, size, i, j, value, groupSize);
                groupSizes[groupCount] = groupSize;
                groupCount++;
            }
        }
    }

    std::cout << "Grup Sayisi: " << groupCount << std::endl;
    for (int i = 0; i < groupCount; i++)
        std::cout << "Grup " << i + 1 << " Boyutu: " << groupSizes[i] << std::endl;

    for (int i = 0; i < size; i++)
        delete[] visited[i];
    delete[] visited;
    delete[] groupSizes;
}

int main()
{
    int size;
    std::cout << "Matris Boyutunu Girin: ";
    std::cin >> size;

    int **matrix = new int*[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            std::cout << "Matris[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
    sameValueCells(matrix, size);
    for (int i = 0; i < size; i++)
        delete[] matrix[i];

    delete[] matrix;
    return 0;
}