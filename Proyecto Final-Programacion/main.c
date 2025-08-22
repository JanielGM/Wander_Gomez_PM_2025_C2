#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// --- Prototipos de funciones ---
// Esto le dice al compilador que estas funciones existen y dónde están
void limpiar_buffer();
void limpiar_pantalla();
void guardar_datos_vehiculos();
void cargar_datos_vehiculos();
void crear_vehiculo();
void borrar_vehiculo();
void modificar_vehiculo();
void listar_vehiculos();
void gestionar_costos_combustible();
void calcular_costo_viaje();
void menu_principal();


// Definición de la estructura para el vehículo
typedef struct
{
    char placa[10];
    char marca[20];
    char modelo[20];
    char tipo_combustible[10];
    float km_x_galon_carretera;
    float km_x_galon_ciudad;
    float costo_gomas;
    float km_gomas;
    float costo_seguro_anual;
    float costo_mantenimiento;
    float km_mantenimiento;
    float costo_vehiculo;
    int vida_util_agnos;
    float depreciacion;
    float km_promedio_agno;
} Vehiculo;

// Variables globales para la gestión de vehículos
Vehiculo *vehiculos = NULL;
int num_vehiculos = 0;

// Variables globales para los costos generales
float costo_combustible_gasolina = 0.0;
float costo_combustible_gasoil = 0.0;

// --- Funciones de Utilidad ---

// Se movió la definición de la función aquí
void limpiar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Función para limpiar la pantalla
void limpiar_pantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// --- Funciones de Gestión de Vehículos ---

void guardar_datos_vehiculos()
{
    FILE *fp = fopen("vehiculos.dat", "wb");
    if (fp == NULL)
    {
        printf("Error al guardar los datos.\n");
        return;
    }
    fwrite(&num_vehiculos, sizeof(int), 1, fp);
    if (num_vehiculos > 0)
    {
        fwrite(vehiculos, sizeof(Vehiculo), num_vehiculos, fp);
    }
    fclose(fp);
    printf("Datos guardados correctamente.\n");
}

void cargar_datos_vehiculos()
{
    FILE *fp = fopen("vehiculos.dat", "rb");
    if (fp == NULL)
    {
        printf("No se encontraron datos de vehiculos. Creando archivo nuevo.\n");
        return;
    }

    fread(&num_vehiculos, sizeof(int), 1, fp);
    if (num_vehiculos > 0)
    {
        vehiculos = (Vehiculo*) malloc(num_vehiculos * sizeof(Vehiculo));
        if (vehiculos == NULL)
        {
            printf("Error de memoria al cargar los datos.\n");
            num_vehiculos = 0;
            fclose(fp);
            return;
        }
        fread(vehiculos, sizeof(Vehiculo), num_vehiculos, fp);
        printf("Se cargaron %d vehiculos.\n", num_vehiculos);
    }

    fclose(fp);
}

void crear_vehiculo()
{
    limpiar_pantalla();
    Vehiculo nuevo_vehiculo;
    printf("\n--- Crear Vehiculo ---\n");
    printf("Placa: ");
    limpiar_buffer();
    fgets(nuevo_vehiculo.placa, sizeof(nuevo_vehiculo.placa), stdin);
    nuevo_vehiculo.placa[strcspn(nuevo_vehiculo.placa, "\n")] = 0;

    printf("Marca: ");
    fgets(nuevo_vehiculo.marca, sizeof(nuevo_vehiculo.marca), stdin);
    nuevo_vehiculo.marca[strcspn(nuevo_vehiculo.marca, "\n")] = 0;

    printf("Modelo: ");
    fgets(nuevo_vehiculo.modelo, sizeof(nuevo_vehiculo.modelo), stdin);
    nuevo_vehiculo.modelo[strcspn(nuevo_vehiculo.modelo, "\n")] = 0;

    printf("Tipo de Combustible (Gasolina/Gasoil): ");
    fgets(nuevo_vehiculo.tipo_combustible, sizeof(nuevo_vehiculo.tipo_combustible), stdin);
    nuevo_vehiculo.tipo_combustible[strcspn(nuevo_vehiculo.tipo_combustible, "\n")] = 0;

    printf("Km por galon en Carretera: ");
    scanf("%f", &nuevo_vehiculo.km_x_galon_carretera);

    printf("Km por galon en Ciudad: ");
    scanf("%f", &nuevo_vehiculo.km_x_galon_ciudad);

    printf("Costo de Gomas: ");
    scanf("%f", &nuevo_vehiculo.costo_gomas);

    printf("Km de vida util de las gomas: ");
    scanf("%f", &nuevo_vehiculo.km_gomas);

    printf("Costo de Seguro anual: ");
    scanf("%f", &nuevo_vehiculo.costo_seguro_anual);

    printf("Costo de Mantenimiento: ");
    scanf("%f", &nuevo_vehiculo.costo_mantenimiento);

    printf("Km de vida util de mantenimiento: ");
    scanf("%f", &nuevo_vehiculo.km_mantenimiento);

    printf("Costo del Vehiculo: ");
    scanf("%f", &nuevo_vehiculo.costo_vehiculo);

    printf("Vida util del vehiculo (agnos): ");
    scanf("%d", &nuevo_vehiculo.vida_util_agnos);

    printf("Depreciacion anual del vehiculo: ");
    scanf("%f", &nuevo_vehiculo.depreciacion);

    printf("Km promedio por agno: ");
    scanf("%f", &nuevo_vehiculo.km_promedio_agno);

    num_vehiculos++;
    vehiculos = (Vehiculo*) realloc(vehiculos, num_vehiculos * sizeof(Vehiculo));
    if (vehiculos == NULL)
    {
        printf("Error de memoria. Saliendo...\n");
        exit(1);
    }
    vehiculos[num_vehiculos - 1] = nuevo_vehiculo;
    printf("\nVehiculo anadido con exito.\n");
    limpiar_buffer();
}

void borrar_vehiculo()
{
    limpiar_pantalla();
    char placa_borrar[10];
    int i, encontrado = 0;

    if (num_vehiculos == 0)
    {
        printf("No hay vehiculos para borrar.\n");
        return;
    }

    printf("\n--- Borrar Vehiculo ---\n");
    printf("Ingrese la placa del vehiculo a borrar: ");
    limpiar_buffer();
    fgets(placa_borrar, sizeof(placa_borrar), stdin);
    placa_borrar[strcspn(placa_borrar, "\n")] = 0;

    for (i = 0; i < num_vehiculos; i++)
    {
        if (strcmp(vehiculos[i].placa, placa_borrar) == 0)
        {
            encontrado = 1;
            for (int j = i; j < num_vehiculos - 1; j++)
            {
                vehiculos[j] = vehiculos[j + 1];
            }
            num_vehiculos--;
            vehiculos = (Vehiculo*) realloc(vehiculos, num_vehiculos * sizeof(Vehiculo));
            printf("Vehiculo con placa %s borrado con exito.\n", placa_borrar);
            break;
        }
    }
    if (!encontrado)
    {
        printf("Vehiculo con placa %s no encontrado.\n", placa_borrar);
    }
}

void modificar_vehiculo()
{
    limpiar_pantalla();
    char placa_modificar[10];
    int i, encontrado = 0;

    if (num_vehiculos == 0)
    {
        printf("No hay vehiculos para modificar.\n");
        return;
    }

    printf("\n--- Modificar Vehiculo ---\n");
    printf("Ingrese la placa del vehiculo a modificar: ");
    limpiar_buffer();
    fgets(placa_modificar, sizeof(placa_modificar), stdin);
    placa_modificar[strcspn(placa_modificar, "\n")] = 0;

    for (i = 0; i < num_vehiculos; i++)
    {
        if (strcmp(vehiculos[i].placa, placa_modificar) == 0)
        {
            encontrado = 1;
            printf("Vehiculo encontrado. Ingrese los nuevos datos:\n");
            printf("Nuevo Costo de Gomas (actual: %.2f): ", vehiculos[i].costo_gomas);
            scanf("%f", &vehiculos[i].costo_gomas);

            printf("Nuevo Costo de Seguro anual (actual: %.2f): ", vehiculos[i].costo_seguro_anual);
            scanf("%f", &vehiculos[i].costo_seguro_anual);

            printf("Vehiculo modificado con exito.\n");
            limpiar_buffer();
            break;
        }
    }
    if (!encontrado)
    {
        printf("Vehiculo con placa %s no encontrado.\n", placa_modificar);
    }
}

void listar_vehiculos()
{
    limpiar_pantalla();
    if (num_vehiculos == 0)
    {
        printf("No hay vehiculos registrados.\n");
        return;
    }
    printf("\n--- Lista de Vehiculos ---\n");
    for (int i = 0; i < num_vehiculos; i++)
    {
        printf("Vehiculo %d:\n", i + 1);
        printf("  Placa: %s\n", vehiculos[i].placa);
        printf("  Marca: %s\n", vehiculos[i].marca);
        printf("  Modelo: %s\n", vehiculos[i].modelo);
        printf("  Tipo Combustible: %s\n", vehiculos[i].tipo_combustible);
        printf("----------------------------------\n");
    }
}

void gestionar_costos_combustible()
{
    limpiar_pantalla();
    printf("\n--- Gestion de Costos de Combustible ---\n");
    printf("Ingrese el costo por galon de Gasolina: ");
    scanf("%f", &costo_combustible_gasolina);
    printf("Ingrese el costo por galon de Gasoil: ");
    scanf("%f", &costo_combustible_gasoil);
    printf("Costos de combustible actualizados.\n");
}

void calcular_costo_viaje()
{
    limpiar_pantalla();
    char placa_viaje[10];
    int i, encontrado = 0;
    float km_viaje, porcentaje_ciudad, km_ciudad, km_carretera, costo_combustible;
    float costo_gomas_viaje, costo_seguro_viaje, costo_mantenimiento_viaje;
    float depreciacion_viaje, costo_total_viaje, costo_por_km;

    if (num_vehiculos == 0)
    {
        printf("No hay vehiculos registrados para calcular viajes.\n");
        return;
    }

    printf("\n--- Calculo de Costo de Viaje ---\n");
    printf("Ingrese la placa del vehiculo: ");
    limpiar_buffer();
    fgets(placa_viaje, sizeof(placa_viaje), stdin);
    placa_viaje[strcspn(placa_viaje, "\n")] = 0;

    for (i = 0; i < num_vehiculos; i++)
    {
        if (strcmp(vehiculos[i].placa, placa_viaje) == 0)
        {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Vehiculo con placa %s no encontrado.\n", placa_viaje);
        return;
    }

    printf("Ingrese los kilometros totales del viaje: ");
    scanf("%f", &km_viaje);
    printf("Ingrese el porcentaje de km en ciudad (ej. 30 para 30%%): ");
    scanf("%f", &porcentaje_ciudad);

    km_ciudad = km_viaje * (porcentaje_ciudad / 100.0);
    km_carretera = km_viaje - km_ciudad;

    if (strcasecmp(vehiculos[i].tipo_combustible, "gasolina") == 0)
    {
        costo_combustible = (km_ciudad / vehiculos[i].km_x_galon_ciudad + km_carretera / vehiculos[i].km_x_galon_carretera) * costo_combustible_gasolina;
    }
    else if (strcasecmp(vehiculos[i].tipo_combustible, "gasoil") == 0)
    {
        costo_combustible = (km_ciudad / vehiculos[i].km_x_galon_ciudad + km_carretera / vehiculos[i].km_x_galon_carretera) * costo_combustible_gasoil;
    }
    else
    {
        costo_combustible = 0;
        printf("Tipo de combustible no valido. No se puede calcular el costo de combustible.\n");
    }

    costo_gomas_viaje = (km_viaje / vehiculos[i].km_gomas) * vehiculos[i].costo_gomas;
    costo_seguro_viaje = (km_viaje / vehiculos[i].km_promedio_agno) * vehiculos[i].costo_seguro_anual;
    costo_mantenimiento_viaje = (km_viaje / vehiculos[i].km_mantenimiento) * vehiculos[i].costo_mantenimiento;
    depreciacion_viaje = (km_viaje / vehiculos[i].km_promedio_agno) * vehiculos[i].depreciacion;

    costo_total_viaje = costo_combustible + costo_gomas_viaje + costo_seguro_viaje + costo_mantenimiento_viaje + depreciacion_viaje;
    costo_por_km = costo_total_viaje / km_viaje;

    printf("\n--- Resultado Desglosado ---\n");
    printf("Costo de Gomas: %.2f\n", costo_gomas_viaje);
    printf("Costo de Seguro: %.2f\n", costo_seguro_viaje);
    printf("Costo de Combustible: %.2f\n", costo_combustible);
    printf("Costo de Mantenimiento: %.2f\n", costo_mantenimiento_viaje);
    printf("Costo de Depreciacion: %.2f\n", depreciacion_viaje);
    printf("---------------------------\n");
    printf("Resultado Costo por KM: %.2f\n", costo_por_km);
    printf("Resultado Costo Total Viaje: %.2f\n", costo_total_viaje);
    limpiar_buffer();
}

// --- Menú principal ---
void menu_principal()
{
    int opcion;
    do
    {
        limpiar_pantalla();
        printf("\n\n--- MENU PRINCIPAL ---\n");
        printf("1. Gestion de Vehiculos\n");
        printf("2. Gestion de Datos Generales\n");
        printf("3. Calculo de Costo de Viaje\n");
        printf("4. Salir y Guardar\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiar_buffer();

        switch (opcion)
        {
        case 1:
            limpiar_pantalla();
            printf("\n--- GESTION DE VEHICULOS ---\n");
            printf("1. Crear Vehiculo\n");
            printf("2. Borrar Vehiculo\n");
            printf("3. Modificar Vehiculo\n");
            printf("4. Listar Vehiculos\n");
            printf("Seleccione una opcion: ");
            scanf("%d", &opcion);
            limpiar_buffer();
            if (opcion == 1) crear_vehiculo();
            else if (opcion == 2) borrar_vehiculo();
            else if (opcion == 3) modificar_vehiculo();
            else if (opcion == 4) listar_vehiculos();
            break;
        case 2:
            gestionar_costos_combustible();
            break;
        case 3:
            calcular_costo_viaje();
            break;
        case 4:
            guardar_datos_vehiculos();
            break;
        default:
            printf("Opcion no valida. Intente de nuevo.\n");
        }
        if (opcion != 4)
        {
            printf("\nPresione ENTER para continuar...");
            limpiar_buffer();
        }
    }
    while (opcion != 4);
}

// --- Función Principal ---
int main(int argc, char *argv[])
{
    cargar_datos_vehiculos();
    menu_principal();
    if (vehiculos != NULL)
    {
        free(vehiculos);
    }
    return 0;
}
