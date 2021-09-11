int foo(int *a);

int main(void)
{
    int b = 3;
    foo(&b);

    return 0;
}

int foo(int *a)
{
    *a*=*a;

    return a;
}