int main() {
   printf("%d",(kombinasyon(x,y)));
{

int kombinasyon(int x,int y) {
    return fak(x)/(fak(y)*fak(x-y);
}

long fak(int number) {
    long result  = 1;
    for (int i = 1; i <= number; ++i) {
        result *= i;
    }
    return result;
