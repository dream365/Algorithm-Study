#include <stdio.h>
#include <vector>

using namespace std;

void setElements(vector<int>& orderVect, int size) {

    for (int i = 0; i < size; i++) {
        int ele;
        scanf("%d", &ele);
        orderVect[i] = ele;
    }
}

void printPostOrder(vector<int>& preOrderVect, int index, vector<int>& subTreeVect) {

    vector<int> left;
    vector<int> right;

    int root = preOrderVect[index];

    bool findRoot = false;

    for (int i = 0; i < subTreeVect.size(); i++) {
        if (subTreeVect[i] == root) {
            findRoot = true;
            continue;
        }

        if (findRoot)
            right.push_back(subTreeVect[i]);
        else
            left.push_back(subTreeVect[i]);
    }

    if (!left.empty())
        printPostOrder(preOrderVect, index + 1, left);

    if(!right.empty())
        printPostOrder(preOrderVect, index + left.size() + 1, right);

    printf("%d ", root);
}

int main()
{
    int C;

    scanf("%d", &C);

    for (int i = 0; i < C; i++) {
        int N;
        scanf("%d", &N);

        vector<int> preOrderVect(N);
        vector<int> inOrderVect(N);

        setElements(preOrderVect, N);
        setElements(inOrderVect, N);

        printPostOrder(preOrderVect, 0, inOrderVect);

        printf("\n");
    }
}