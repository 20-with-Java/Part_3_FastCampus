#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int A, B, N, t, m;
    char c;
    std::vector<int> blueOrder, redOrder;
    std::queue<int> blue, red;

    scanf("%d %d %d", &A, &B, &N);

    for(int n = 0; n < N; n++)
    {
        scanf("%d %c %d", &t, &c, &m);

        if('B' == c)
        {
            if(blue.empty() == false && t < blue.back() + A)
            {
                t = blue.back() + A;
            }

            for(int i = 0; i < m; i++)
            {
                blue.push(t);
                t += A;
            }
        }
        else
        {
            if(red.empty() == false && t < red.back() + B)
            {
                t = red.back() + B;
            }

            for(int i = 0; i < m; i++)
            {
                red.push(t);
                t += B;
            }
        }
    }

    int orderNumber;
    for(orderNumber = 1; blue.empty() == false && red.empty() == false; orderNumber++)
    {
        if(blue.front() <= red.front())
        {
            blueOrder.push_back(orderNumber);
            blue.pop();
        }
        else
        {
            redOrder.push_back(orderNumber);
            red.pop();
        }
    }

    for(;blue.empty() == false; orderNumber++)
    {
        blueOrder.push_back(orderNumber);
        blue.pop();
    }

    for(;red.empty() == false; orderNumber++)
    {
        redOrder.push_back(orderNumber);
        red.pop();
    }

    printf("%d\n", blueOrder.size());
    for(int num : blueOrder)
    {
        printf("%d ", num);
    }
    printf("\n%d\n", redOrder.size());
    for(int num : redOrder)
    {
        printf("%d ", num);
    }

    return 0;
}