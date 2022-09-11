var compute_days(var age, var days)
{
  return age * days;
}
 
function main()
{
  printf("I am %.f days old!",compute_days(33,365.25));
}