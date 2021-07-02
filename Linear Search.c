int linear_search(int *arr, int val, int size) // search single direction
{
    for(int i = 0; i < size; i++)
        if(arr[i] == val)
            return i;

    return -1;
}

int improved_linear_search(int *arr, int val, int size) // search both direction
{
    for(int i = 0; i < size;)
    {
        for(int j = size - 1; j >=0;)
        {
            if(arr[i] == val)
                return i;

            if(arr[j] == val)
                return j;

            i++;
            j--;

            if(i == j)
              return -1;
        }
    }
}
