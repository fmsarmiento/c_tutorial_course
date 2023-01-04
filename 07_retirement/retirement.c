#include<stdio.h>
#include<stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double calculate(int startAge, double initial, retire_info info) {
  double end_of_month = initial;
  for(int i = 0;i<info.months;i++) {
    printf("Age %3d month %2d you have $%.2lf\n", startAge/12, startAge%12, end_of_month);
    end_of_month = end_of_month + (end_of_month * info.rate_of_return) + info.contribution;
    startAge = startAge+1;
  }
  return end_of_month;
}

void retirement (int startAge, double initial, retire_info working, retire_info retired) {
  double end_of_month = calculate(startAge, initial, working);
  startAge = startAge + working.months;
  calculate(startAge, end_of_month, retired);
}

int main() {
  retire_info working;
  retire_info retired;
  working.months=489;
  working.contribution=1000;
  working.rate_of_return=0.045/12;
  retired.months=384;
  retired.contribution=-4000;
  retired.rate_of_return=0.01/12;
  int startAge = 327;
  double savings = 21345;
  retirement(startAge, savings,  working, retired);
  return 0;
}
