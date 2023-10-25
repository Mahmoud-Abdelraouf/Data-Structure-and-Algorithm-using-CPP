% Fibonacci indices
indices = [10, 20, 30, 40];

% Fibonacci results (recursive and iterative)
recursiveFib = [55, 6765, 832040, 102334155];
iterativeFib = [55, 6765, 832040, 102334155];

% Execution times for recursive Fibonacci (in microseconds)
recursiveTime = [0, 39, 4847, 609154];

% Execution times for iterative Fibonacci (in microseconds)
iterativeTime = [0, 0, 0, 0];

% Create subplots for Fibonacci results and execution times
subplot(2, 1, 1);
plot(indices, recursiveFib, '-o', 'LineWidth', 2, 'MarkerSize', 8, 'DisplayName', 'Recursive');
hold on;
plot(indices, iterativeFib, '-o', 'LineWidth', 2, 'MarkerSize', 8, 'DisplayName', 'Iterative');
xlabel('Fibonacci Index');
ylabel('Fibonacci Result');
title('Fibonacci Results');
legend('show');
grid on;

subplot(2, 1, 2);
plot(indices, recursiveTime, '-o', 'LineWidth', 2, 'MarkerSize', 8, 'DisplayName', 'Recursive');
hold on;
plot(indices, iterativeTime, '-o', 'LineWidth', 2, 'MarkerSize', 8, 'DisplayName', 'Iterative');
xlabel('Fibonacci Index');
ylabel('Execution Time (microseconds)');
title('Execution Times');
legend('show');
grid on;
