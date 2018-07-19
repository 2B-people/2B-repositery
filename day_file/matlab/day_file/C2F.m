c = 0.0;
f = 0.0;
while 1
    x = input('please input c');
    if isempty(x) == 0
        c = x;
        f = (c-32)*0.91;
        disp(f);
    else
        break;
    end
end