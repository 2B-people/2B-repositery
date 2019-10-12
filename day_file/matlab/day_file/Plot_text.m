t = 1:0.01:2;
f = t.^2;
g = sin(2*pi.*t);
plot(t,f,'-k',t,g,'or')
legend('t^2','sin(2\pit)')
title('Mini Assignment #1');
xlabel('Time(ms)');
ylabel('f(t)');