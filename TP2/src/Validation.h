#ifndef VALIDATION_H_
#define VALIDATION_H_

/** \brief el usuario inserta un int
 *
 * \param mensaje[] char
 * \return int
 *
 */
int getInt(char mensaje[]);
/** \brief el usuario inserta un string
 *
 * \param mensaje[] char
 * \param input[] char
 * \return void
 *
 */
void getString(char mensaje[], char input[]);
/** \brief el usuario inserta un float
 *
 * \param mensaje[] char
 * \return float
 *
 */
float getFloat(char mensaje[]);
/** \brief valida si un string tiene solo letras
 *
 * \param str[] char
 * \return int return 1(true) - 0(false)
 *
 */
int isOnlyLetters(char str[]);
/** \brief valida si el numero es positivo
 *
 * \param number float
 * \return int return 1(true) - 0(false)
 *
 */
int isPositive(float numero);

#endif /* VALIDATION_H_ */
