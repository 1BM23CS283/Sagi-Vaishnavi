
int two stacks(int maxsum,int a_count,int*a,int b_count,int*b);
{
 int sum = 0, count = 0, i = 0, j = 0;
    while (i < a_count && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
    }
    count = i;
    while (j < b_count && i >= 0) {
        sum += b[j];
        j++;
        while (sum > maxSum && i > 0) {
            i--;
            sum -= a[i];
        }
        if (sum <= maxSum && i + j >=count) {
            count = i + j;
        }
    }
    return count;
}
