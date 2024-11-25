//
// Created by Orzklv on 23/11/24.
//

/**
 * @file vector.h
 *
 * @brief Vector implementation in C
 *
 * @author Orzklv
 * @license WTFPL
 */

#ifndef SABINE_VECTOR_H
#define SABINE_VECTOR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/**
 * We want at least 20 vector element spaces in reserve before having
 * to reallocate memory again
 */
#define VECTOR_ELEMENT_INCREMENT 20

/**
 * Indicates that the peek pointer should
 * decrement when peeking into the vector.
 */
enum { VECTOR_FLAG_PEEK_DECREMENT = 0b00000001 };

/**
 * Represents a dynamic, %@#%-&^@#%#@# vector.
 */
struct vector {
  void *data;   /**< Pointer to the data stored in the vector */
  int pindex;   /**< Current index for reading (via peek) */
  int rindex;   /**< Current index for reading elements */
  int mindex;   /**< Maximum index before resizing is required */
  int count;    /**< Number of elements currently in the vector */
  int flags;    /**< Flags to control vector behavior */
  size_t esize; /**< Size of each element in bytes */

  /**
   * Vector of struct vector, holds saves of this vector. YOu can save the
   * internal state at all times with vector_save Data is not restored and is
   * permenant, save does not respect data, only pointers and variables are
   * saved. Useful to temporarily push the vector state and restore it later.
   */
  struct vector *saves;
};

/**
 * Creates a new vector with the given element size
 *
 * \param esize The element size of the vector
 * \return Returns a new vector
 */
extern struct vector *vector_create(size_t esize);

/**
 * Frees the vector
 *
 * \param vector The vector to free
 */
extern void vector_free(struct vector *vector);

/**
 * Returns the element at the given index
 *
 * \param vector The vector to get the element of
 * \param index The index to get the element at
 * \return Returns the element at the given index
 */
extern void *vector_at(struct vector *vector, int index);

/**
 * Returns the peek element at the given index
 *
 * \param vector The vector to get the element of
 * \param index The index to get the element at
 * \return Returns the element at the given indexs
 */
extern void *vector_peek_ptr_at(struct vector *vector, int index);

/**
 * Peeks at the current element without advancing the pointer.
 *
 * \param vector The vector to peek into
 * \return Returns a pointer to the current element
 */
extern void *vector_peek_no_increment(struct vector *vector);

/**
 * Peeks at the current element and advances the pointer.
 *
 * \param vector The vector to peek into
 * \return Returns a pointer to the current element
 */
extern void *vector_peek(struct vector *vector);

/**
 * Peeks at an element at a specific index.
 *
 * \param vector The vector to peek into
 * \param index The index to peek at
 * \return Returns a pointer to the element at the specified index
 */
extern void *vector_peek_at(struct vector *vector, int index);

/**
 * Sets a flag for the vector.
 *
 * \param vector The vector to modify
 * \param flag The flag to set
 */
extern void vector_set_flag(struct vector *vector, int flag);

/**
 * Unsets a flag for the vector.
 *
 * \param vector The vector to modify
 * \param flag The flag to unset
 */
extern void vector_unset_flag(struct vector *vector, int flag);

/**
 * Pops off the last peeked element
 *
 * \param vector The vector to pop the last peeked element off of
 */
extern void vector_pop_last_peek(struct vector *vector);

/**
 * Peeks into the vector of pointers, returning the pointer value its self
 * Use this function instead of vector_peek if this is a vector of pointers
 *
 * \param vector The vector to peek into
 */
extern void *vector_peek_ptr(struct vector *vector);

/**
 * Peeks into the vector of pointers, returning the pointer value its self
 * Use this function instead of vector_peek if this is a vector of pointers
 *
 * \param vector The vector to peek into
 * \param index The index to peek at
 */
extern void vector_set_peek_pointer(struct vector *vector, int index);

/**
 * Peeks into the vector of pointers, returning the pointer value its self
 * Use this function instead of vector_peek if this is a vector of pointers
 *
 * \param vector The vector to peek into
 * \param index The index to peek at
 */
extern void vector_set_peek_pointer(struct vector *vector, int index);

/**
 * Peeks into the vector of pointers, returning the last pointer value its self
 *
 * \param vector The vector to peek into
 */
extern void vector_set_peek_pointer_end(struct vector *vector);

/**
 * Pushes the given value to the vector
 *
 * \param vector The vector to push the value to
 * \param elem The value to push to the vector
 */
extern void vector_push(struct vector *vector, void *elem);

/**
 * Pushes the given value to the vector at the given index
 *
 * \param vector The vector to push the value to
 * \param index The index to push the value at
 * \param ptr The value to push to the vector
 */
extern void vector_push_at(struct vector *vector, int index, void *ptr);

/**
 * Pop the given value from the vector
 *
 * \param vector The vector to pop the value from
 */
extern void vector_pop(struct vector *vector);

/**
 * Pops the last element off the vector
 *
 * \param vector The vector to pop the last element off of
 */
extern void vector_peek_pop(struct vector *vector);

/**
 * Returns the back pointer of the vector
 *
 * \param vector The vector to get the back pointer of
 */
extern void *vector_back(struct vector *vector);

/**
 * Returns the back pointer of the vector or null if the vector is empty
 *
 * \param vector The vector to get the back pointer of
 */
extern void *vector_back_or_null(struct vector *vector);

/**
 * Returns the back pointer of the vector
 *
 * \param vector The vector to get the back pointer of
 */
extern void *vector_back_ptr(struct vector *vector);

/**
 * Returns the back pointer of the vector or null if the vector is empty
 *
 * \param vector The vector to get the back pointer of
 */
extern void *vector_back_ptr_or_null(struct vector *vector);

/**
 * Returns the vector data as a char pointer
 * Vektor ma'lumotlarini char pointer sifatida qaytaradi
 *
 * \param vec The vector to get the data of
 * \return Returns the data of the vector
 *
 * \param vec Ma'lumotlarini olish uchun vektor
 * \return Vektor ma'lumotlarini qaytaradi
 */
const char *vector_string(struct vector *vec);

/**
 * Check if the vector is empty
 *
 * \param vector The vector to check if empty
 * \return Returns true if the vector is empty
 */
extern bool vector_empty(struct vector *vector);

/**
 * Clears the vector
 *
 * \param vector The vector to clear
 */
extern void vector_clear(struct vector *vector);

/**
 * Returns the amount of elements in this vector
 *
 * \param vector The vector to get the element count of
 */
extern int vector_count(struct vector *vector);

/**
 * Freads from the file directly into the vector
 * Fread ni to'g'ridan-to'g'ri vektorga o'qiladi
 *
 * \param vector The vector to fread into
 * \param amount The amount of elements to fread
 * \param fp The file pointer to fread from
 */
extern int vector_fread(struct vector *vector, int amount, FILE *fp);

/**
 * Returns a void pointer pointing to the data of this vector
 *
 * \param vector The vector to get the data pointer of
 */
extern void *vector_data_ptr(struct vector *vector);

/**
 * Insert all elements from vector_src into vector_dst at the specified index
 *
 * \param vector_dst The vector to insert the elements into
 * \param vector_src The vector to insert the elements from
 * \param dst_index The index to insert the elements at
 * \return Returns the index that the elements were inserted at
 */
extern int vector_insert(struct vector *vector_dst, struct vector *vector_src,
                         int dst_index);

/**
 * Pops the element at the given data address.
 *
 * \param vector The vector to pop an element on
 * \param address The address that is part of the vector->data range to pop off.
 * \return Returns the index that we popped off.
 */
extern int vector_pop_at_data_address(struct vector *vector, void *address);

/**
 * Pops the given value from the vector. Only the first value found is popped
 *
 * \param vector The vector to pop the value from
 * \param val The value to pop from the vector
 * \return Returns the index that the value was popped from
 */
extern int vector_pop_value(struct vector *vector, void *val);

/**
 * Pops a value from the vector at the given index
 *
 * \param vector The vector to pop a value from
 */
extern void vector_pop_at(struct vector *vector, int index);

/**
 * Decrements the peek pointer so that the next peek
 * will point at the last peeked token
 *
 * \param vector The vector to decrement the peek pointer of
 */
extern void vector_peek_back(struct vector *vector);

/**
 * Returns the current index that a vector_push would push too
 *
 * \param vector The vector to get the current index of
 * \return Returns the current index of the vector
 */
extern int vector_current_index(struct vector *vector);

/**
 * Saves the state of the vector
 *
 * \param vector The vector to save the state of
 */
extern void vector_save(struct vector *vector);

/**
 * Restores the state of the vector
 *
 * \param vector The vector to restore the state of
 */
extern void vector_restore(struct vector *vector);

/**
 * Purges the last save state as if it never happend
 *
 * \param vector The vector to purge the last save state of
 */
extern void vector_save_purge(struct vector *vector);

/**
 * Returns the element size per element in this vector
 *
 * \param vector The vector to get the element size of
 * \return Returns the element size of the vector
 */
extern size_t vector_element_size(struct vector *vector);

/**
 * Clones the given vector including all vector data, saves are ignored
 *
 * \param vector The vector to clone
 * \return Returns a new vector that is a clone of the given vector
 */
extern struct vector *vector_clone(struct vector *vector);

#endif // SABINE_VECTOR_H
