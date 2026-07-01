//Get number with at most two distinct digits in its decimal representation
        
int y = 1;
while(x > 0){ 
y *= 10;
x /= 10; }
cout << y + 1;
