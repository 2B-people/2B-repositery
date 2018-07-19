A =  [0 -1 4;9 -14 25;-34 49 64];
B = zeros(3,3);
for i =1:size(A,1)
    for j = 1:size(A,2)
        if A(i,j)<0
            B(i,j)= -A(i,j);
        else
            B(i,j)= A(i,j);
        end
    end
end

% B = A;
% B(B<0) = -B(B<0);

