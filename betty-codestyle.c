#include <unistd.h>

/**
 * calculate_area_rect - Calculates the area of a rectangle
 * @length: Length of the rectangle
 * @breadth: Breadth of the rectangle
 *
 * Return: The area of the rectangle
 */
int calculate_area_rect(int length, int breadth)
{
	int area = length * breadth;

	return (area);
}

int main(void)
{
	int length = 0;
	int breadth = 0;
	int area = 0;
	char result[20];

	write(STDOUT_FILENO, "Enter the length of the rectangle: ", 33);
	read(STDIN_FILENO, &length, sizeof(length));

	write(STDOUT_FILENO, "Enter the breadth of the rectangle: ", 34);
	read(STDIN_FILENO, &breadth, sizeof(breadth));

	area = calculate_area_rect(length, breadth);

	snprintf(result, sizeof(result), "%.2f", area);
	write(STDOUT_FILENO, "The area of the rectangle is: ", 29);
	write(STDOUT_FILENO, result, sizeof(result));
	write(STDOUT_FILENO, "\n", 1);

	return (0);
}

