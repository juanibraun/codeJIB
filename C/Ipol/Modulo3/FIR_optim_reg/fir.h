#define TAP_LENGTH 128 // Cantidad de coeficientes del filtro.
#define SIGNAL_LENGTH 1024 // Cantidad de muestras;
#define update_p(p){ \
    if(p!=0){        \
      p = (p+1) % p; \
    }else{           \
      p += 1;        \			     
    }                \
} 
 
typedef float sample_t;
 
void ini_fir(sample_t coefs[]);
 
sample_t fir(sample_t muestra);
 

