#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int plot(float a, float b, float c, float p, float q, float r){
    // the equations are ax + by = c   and    px + qy = r
    
    float x, y;
    float var1, var2;
    
    var1 = (float)((c*q - r*b)/(a*q - p*b));
    var2 = (float)((a*r - p*c)/(a*q - p*b));
    
    if(var1 == 0){
        var1 = 0;
    }
    if(var2 == 0){
        var2 = 0;
    }
    
    for(y = var2-10; y <= var2+10; y++)
    {
        for(x = var1-10; x <= var1+10; x++){
            if(c==((a*x) + (b*y)))
            {
                printf("1");
            }
            else if(r==((p*x) + (q*y)))
            {
               printf("2");
            }
            else{
                printf(" ");
            }
        }printf("\n");
    }
    return 1;
}

int substitution(float a, float b, float c, float p, float q, float r){
    /*
    Using substitution, in the equation ax+by=c,
    value of y turned out to be (c-ax)/b
    
    Putting this value in second equation, we get:
    x = (cq-rb)/(aq-pb)
    y = (ar-pc)/(aq-pb)
    
    */
    float var1, var2;
    
    var1 = (float)((c*q - r*b)/(a*q - p*b));
    var2 = (float)((a*r - p*c)/(a*q - p*b));
    
    if(var1 == 0){
        var1 = 0;
    }
    if(var2 == 0){
        var2 = 0;
    }
    printf("\n SOLUTION USING SUBSTITUTION \n");
    printf("\n Value of x : %.4f", var1);
    printf("\n Value of y : %.4f", var2);
    
    return 1;
}

int matrix(float a, float b, float c, float p, float q, float r){
    /*
    In this method, the way to solve equations is AX = B,
    where A, B and X; all are matrices
    
    A =  [a b]  i.e. coefiicients of the variables
         [p q]
         
    X =  [x]    i.e. the variables
         [y]
        
    B =  [c]    i.e. the constants in the equations
         [r]
        
        
    Now, to solve for X, X = (A)^(-1) * B
    
    Here, A^(-1) = adj(A)/det(A), ,meaning adjoint of A divided by determinant of A
    */
    
    int i,j;
    float minor[2][2], cofactor[2][2], adjoint[2][2], det, var1, var2;
    float matrix[2][2] = {{a, b}, {p, q}};
    
    det = ((a*q) - (p*b));
    printf("\n\n SOLUTION USING MATRIX METHOD \n");
    printf("\n The value of determinant value of matrix A is  %.4f\n", det);
    
    //Developing the Minor Matrix
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            minor[i][j] = matrix[!i][!j];
        }
    }
    
    //Developing the Cofactor Matrix
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            cofactor[i][j] = minor[i][j] * pow(-1, (i+j));
        }
    }

    //Developing the Adjoint Matrix
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            adjoint[i][j] = cofactor[j][i];
        }
    }
    
    printf("\n Original Matrix \n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%.4f\t", matrix[i][j]);
        }printf("\n");
    }
    
    printf("\n Minor Matrix\n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%.4f\t", minor[i][j]);
        }printf("\n");
    }

    printf("\n Cofactor Matrix\n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%.4f\t", cofactor[i][j]);
        }printf("\n");
    }

    printf("\n Adjoint Matrix\n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%.4f\t", adjoint[i][j]);
        }printf("\n");
    }
    
    var1 = (float)(((adjoint[0][0]*c) + (adjoint[0][1]*r)) / det);
    var2 = (float)(((adjoint[1][0]*c) + (adjoint[1][1]*r)) / det);
    
    if(var1 == 0){
        var1 = 0;
    }
    if(var2 == 0){
        var2 = 0;
    }
    printf("\n\n");
    printf("\n Value of x : %.4f", var1);
    printf("\n Value of y : %.4f", var2);

    return 1;
}

int solvable(float a, float b, float c, float p, float q, float r){
    float r1, r2, r3; 
    
    // 3 ratios which can be used to determine the solution 
    r1 = (float)(a/p);
    r2 = (float)(b/q);
    r3 = (float)(c/r);
    
    if(r1 != r2){
        // if a/p = b/q, there exists a unique solution
        return 1;
    }
    
    else{
        if(r2 == r3){
            // if a/p = b/q = c/r, this means that these 2 lines are exactly the same
            return 2;
        }
        else{
            // this represents 2 different parallel lines
            return 0;
        }
    }
    return 0;
}
int main()
{
    float a,b,c,p,q,r;
    printf("Program to solve Linear Equations");
    
    printf("\n General equations look like:  ax+by=c  and  px+qy=r");
    printf("\nEnter the parameters : \n");
    printf("\nEnter a :");
    scanf("%f", &a);
    printf("\nEnter b :");
    scanf("%f", &b);
    printf("\nEnter c :");
    scanf("%f", &c);
    printf("\nEnter p :");
    scanf("%f", &p);
    printf("\nEnter q :");
    scanf("%f", &q);
    printf("\nEnter r :");
    scanf("%f", &r);
    
    if(solvable(a,b,c,p,q,r) == 1){
        
        printf("\n The system of linear equations has a unique solution");
        
        substitution(a,b,c,p,q,r);
        
        matrix(a,b,c,p,q,r);
        
        printf("\n\n\n PRINTING THE PLOT FOR THE SET OF EQUATIONS \n");
        plot(a,b,c,p,q,r);
        
        
    }
    else if(solvable(a,b,c,p,q,r) == 2){
        printf("\n The system of linear equations has infinitely many solutions");
    }
    else{
        printf("\nThe system of Linear equations has no real solution");
    }
    
    return 0;
}

