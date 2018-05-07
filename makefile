clean:
	find . \( -name '*~' -o -name '\#*\#' \
	-o -name '*.o' \
	-o -name '*.log' -o -name '*.aux' \
	\) -delete
