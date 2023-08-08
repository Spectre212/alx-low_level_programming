#include "main.h"

/**
 * append_text_to_file - Appends block of text to the end of a file.
 * @filename: ptr to the name of the file.
 * @text_content: The string to be added to the end of the file.
 * Return: If the funct fails or the filename does not exist rtn -1.
 *      If the file does not exist or the user lacks write permissions rtn -1.
 *      else rtn - 1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
