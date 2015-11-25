    function [xk errorSum] = PID(A,B,xref,xk,errorSum)
    %% Parameters
    uk=[0;0];
    Kp=0.6;
    Ki=0;
    Kd=0;
    error=0;

    %% Generate xk
    errorD=error-(xref-xk);
    error=(xref-xk);
    errorSum=errorSum+error;
    Cpid=pid(Kp,Ki,Kd);
    uk=error*Cpid.Kp+errorSum*Cpid.Ki+errorD*Cpid.Kd;      
    xk=A*xk+B*uk;
    end