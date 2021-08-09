#include<bits/stdc++.h>
#include<math.h>

using namespace std;

void number_of_trees_generated_unlabeled_unlabeled(int);

int main()
{
    number_of_trees_generated_unlabeled_unlabeled(10);
    return 0;
}

void number_of_trees_generated_unlabeled_unlabeled(int nodes)
{

    /** Catalan Number (Formula for finding how many trees can be make by given unlabeled nodes)
      T(n) = 2n
               Cn
             -------
             (n + 1)
    */

    if(nodes < 0)
        cout<<-1;
    else
    {
        long long int n = nodes * 2;
        long long int fact{1};
        long long int catalon{1};

        for(int i = n; i > nodes; i--)
            fact *= i;

        for(int i = nodes; i >= 1; i--)
            catalon *= i;

        long long int num_of_trees = ((fact / catalon) / (nodes + 1));

        long long int possible_max_height_trees = pow(2, nodes - 1); //2 ^ n - 1

        /** Catalan Number (Formula for finding how many trees can be make by given labeled nodes)
        T(n) = 2n
              Cn
            ------- x n!
            (n + 1)
        */

        fact = 1;

        for(int i = nodes; i >= 1; i--)
            fact *= i;

        long long int possible_max_permutation{1};
        possible_max_permutation = num_of_trees * fact;

        cout<<"You entered " << nodes << " nodes"<<endl;
        cout<<"Number of trees generated, unlabeled nodes -> "<<num_of_trees<<endl;
        cout<<"Number of possible max height trees -> "<<possible_max_height_trees<<endl;
        cout<<"Number of trees generated along with permutation, labeled nodes -> "<<possible_max_permutation;
    }
}

