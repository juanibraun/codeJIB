#define TAP_LENGTH 4 // Cantidad de coeficientes del filtro.
#define SIGNAL_LENGTH 10 // Cantidad de muestras;
 
typedef float sample_t;
 
void ini_fir(sample_t coefs[]);
 
sample_t fir(sample_t muestra);
 
void update_p(int paso);