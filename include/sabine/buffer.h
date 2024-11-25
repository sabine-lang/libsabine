//
// Created by Orzklv on 25/11/24.
//

/**
 * @file buffer.h
 *
 * @brief Buffer implementation in C
 *
 * @author Orzklv
 * @license WTFPL
 */

#ifndef BUFFER_H
#define BUFFER_H

#include <stddef.h>

/**
 * Default size increment for buffer reallocation.
 */
#define BUFFER_REALLOC_AMOUNT 2000

/**
 * Structure representing a dynamic buffer for character data.
 */
struct buffer {
  char *data; /**< Pointer to the dynamically allocated buffer data */

  int rindex; /**< Index for the next character to read */
  int len;    /**< Current length of data written to the buffer */
  int msize;  /**< Maximum allocated size of the buffer */
};

/**
 * Creates a new buffer with an initial allocation.
 *
 * \return Returns a pointer to the newly created buffer
 */
extern struct buffer *buffer_create();

/**
 * Reads the next character from the buffer.
 *
 * Advances the read index after reading the character.
 * Returns -1 if the read index exceeds the buffer length.
 *
 * \param buffer The buffer to read from
 * \return Returns the next character or -1 if no more characters
 */
extern char buffer_read(struct buffer *buffer);

/**
 * Peeks at the next character in the buffer without advancing the read index.
 *
 * Returns -1 if the read index exceeds the buffer length.
 *
 * \param buffer The buffer to peek at
 * \return Returns the next character or -1 if no more characters
 */
extern char buffer_peek(struct buffer *buffer);

/**
 * Extends the allocated size of the buffer.
 *
 * Increases the maximum allocated size of the buffer by the specified amount.
 *
 * \param buffer The buffer to extend
 * \param size The additional size to allocate
 */
extern void buffer_extend(struct buffer *buffer, size_t size);

/**
 * Writes formatted data to the buffer.
 *
 * Ensures the buffer has enough space, then writes the formatted string
 * to the buffer. Adds a null terminator to the string.
 *
 * \param buffer The buffer to write to
 * \param fmt The format string
 * \param ... Additional arguments for the format string
 */
extern void buffer_printf(struct buffer *buffer, const char *fmt, ...);

/**
 * Writes formatted data to the buffer without a null terminator.
 *
 * Ensures the buffer has enough space, then writes the formatted string
 * to the buffer without adding a null terminator.
 *
 * \param buffer The buffer to write to
 * \param fmt The format string
 * \param ... Additional arguments for the format string
 */
extern void buffer_printf_no_terminator(struct buffer *buffer, const char *fmt,
                                        ...);

/**
 * Writes a single character to the buffer.
 *
 * Ensures the buffer has enough space, then writes the character to the buffer.
 *
 * \param buffer The buffer to write to
 * \param c The character to write
 */
extern void buffer_write(struct buffer *buffer, char c);

/**
 * Returns a pointer to the raw data in the buffer.
 *
 * This function does not copy or modify the data; it only returns the
 * pointer to the data.
 *
 * \param buffer The buffer to retrieve the data pointer from
 * \return Returns a pointer to the buffer's data
 */
extern void *buffer_ptr(struct buffer *buffer);

/**
 * Frees the memory allocated for the buffer.
 *
 * This function releases the memory used by the buffer's data
 * and the buffer structure itself.
 *
 * \param buffer The buffer to free
 */
extern void buffer_free(struct buffer *buffer);

#endif // BUFFER_H
