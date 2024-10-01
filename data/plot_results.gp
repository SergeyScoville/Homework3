# gnuplot script to plot Result vs Ti
set datafile separator ","    # CSV file separator

set logscale x
set xrange [*:0.0015]
set xlabel "R Values (log(1 - X))"
set ylabel "Final Distance"

# Optional: Customize the plot appearance
set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 1.5  # Line and point style
set terminal pdfcairo
set output "results_T_1510_rValues.pdf"  # Output file

# Plot the data from the file
plot "results_T_1510_rValues.csv" using (1 - $1):2 with linespoints pointtype 7 pointsize 0.5 linecolor rgb "blue" title "Distance of last path"

