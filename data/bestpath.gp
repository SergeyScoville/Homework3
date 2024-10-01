set xlabel "X Coordinate"
set ylabel "Y Coordinate"
set datafile separator ","
set terminal pdfcairo
set output "bestpath.pdf"
plot "best_path.csv" using 1:2 with linespoints pointtype 7 pointsize 0.5 linecolor rgb "blue" title "Best path"
