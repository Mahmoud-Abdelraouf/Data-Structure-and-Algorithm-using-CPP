% Given data for merge sort
mergeArraySizes = [10, 100, 1000, 10000, 100000, 1000000, 10000000];
mergeSortingTimes = [2, 27, 210, 1062, 11819, 131011, 1464722]; % Merge sort times in microseconds

% Given data for selection sort
selectionArraySizes = [10, 100, 1000, 10000, 100000];
selectionSortingTimes = [1, 26, 1253, 96553, 9665723]; % Selection sort times in microseconds

% Plotting merge sort data
loglog(mergeArraySizes, mergeSortingTimes, '-o', 'LineWidth', 2, 'MarkerSize', 8, 'DisplayName', 'Merge Sort');
hold on;

% Plotting selection sort data
loglog(selectionArraySizes, selectionSortingTimes, '-s', 'LineWidth', 2, 'MarkerSize', 8, 'DisplayName', 'Selection Sort');

xlabel('Number of Elements (log scale)');
ylabel('Sorting Time (microseconds, log scale)');
title('Merge Sort vs Selection Sort Performance');
grid on;

% Adding data points to the plot for merge sort
text(mergeArraySizes, mergeSortingTimes, arrayfun(@num2str, mergeArraySizes, 'UniformOutput', false), ...
    'VerticalAlignment','bottom', 'HorizontalAlignment','right');

% Adding data points to the plot for selection sort
text(selectionArraySizes, selectionSortingTimes, arrayfun(@num2str, selectionArraySizes, 'UniformOutput', false), ...
    'VerticalAlignment','bottom', 'HorizontalAlignment','right');

% Displaying legend
legend('Location', 'Best');

% Formatting the plot
set(gca, 'XScale', 'log', 'YScale', 'log');
hold off;
