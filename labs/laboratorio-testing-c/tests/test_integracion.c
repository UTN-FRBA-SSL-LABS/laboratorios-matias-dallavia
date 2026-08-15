#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_compra_con_descuento(void){
    printf("\n[aplicar descuento del 10 porciento a compra de carrito]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 2};
    Producto j = {"Pan", 200, 3};  
    carrito_agregar(&c, j);
    carrito_agregar(&c, p);
    ASSERT_IGUAL(1300, carrito_total(&c));  /* <-- completar el valor esperado */
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10) );
}
/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_agregar_hasta_llenar(){
    printf("\n[agregar productos hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    Producto j = {"Pan", 200, 1};
    for (size_t i = 0; i < MAX_ITEMS; i++)
        carrito_agregar(&c, p);
    ASSERT_IGUAL(MAX_ITEMS, c.cantidad);  /* <-- completar el valor esperado */
    ASSERT_IGUAL(0, carrito_agregar(&c, j));  /* <-- completar el valor esperado */
    ASSERT_IGUAL(MAX_ITEMS, c.cantidad);  /* <-- completar el valor esperado */

}


/* TODO: escribir test_agregar_hasta_llenar() */

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
