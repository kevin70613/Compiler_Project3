@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
declare i32 @printf(i8*, ...)
@x = common global i32 0, align 4
define i32 @func() #0 {
%test = alloca i32, align 4
%a = alloca i32, align 4
%b = alloca i32, align 4
%c = alloca double, align 8
%d = alloca double, align 8
%e = alloca [20 x i32], align 16
%f = alloca [15 x i32], align 16
%g = alloca i32, align 4
store i32 12345, i32* %test, align 4
%1 = load i32* %test, align 4
%2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str, i32 0, i32 0), i32 %1)
ret i32 0

}
define i32 @main() #0 {
%a = alloca i32, align 4
%b = alloca i32, align 4
%c = alloca double, align 8
%d = alloca double, align 8
%e = alloca [20 x i32], align 16
%f = alloca [15 x i32], align 16
%g = alloca i32, align 4
store i32 1, i32* %a, align 4
store i32 2, i32* %b, align 4
store double 3.3,double* %c, align 8
store double 4.0,double* %d, align 8
%1 = load i32* %a, align 4
%2 = sitofp i32 %1 to double
%3 = load double* %c, align 8
%4 = fsub double %2, %3
%5 = fptosi double %4 to i32
store i32 %5, i32* %g, align 4
%6 = load i32* %b, align 4
%7 = sitofp i32 %6 to double
%8 = load double* %c, align 8
%9 = fmul double %7, %8
store double %9, double* %d, align 8
%10 = load double* %d, align 8
%11 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), double %10)
%12 = load i32* %a, align 4
%13 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str, i32 0, i32 0), i32 %12)
%14 = getelementptr inbounds [20 x i32]* %e, i32 0, i64 0
store i32 1, i32* %14, align 4
%15 = getelementptr inbounds [15 x i32]* %f, i32 0, i64 2
store i32 3, i32* %15, align 4
%16 = getelementptr inbounds [15 x i32]* %f, i32 0, i64 4
store i32 5, i32* %16, align 4
%17 = getelementptr inbounds [15 x i32]* %f, i32 0, i64 4
%18 = getelementptr inbounds [20 x i32]* %e, i32 0, i64 0
%19 = load i32* %18, align 4
%20 = getelementptr inbounds [15 x i32]* %f, i32 0, i64 2
%21 = load i32* %20, align 4
%22 = add nsw i32 %19, %21
store i32 %22, i32* %17, align 4
%23 = getelementptr inbounds [15 x i32]* %f, i32 0, i64 4
%24 = load i32* %23, align 4
store i32 %24, i32* @x, align 4
%25 = load i32* @x, align 4
%26 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str, i32 0, i32 0), i32 %25)
%27 = call i32 @func()
ret i32 0

}
