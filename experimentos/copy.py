import os

def copiar_nombres_archivos(directorio, archivo_salida="nombres_archivos.txt"):
    try:
        # Obtener la lista de archivos y carpetas en el directorio
        nombres = os.listdir(directorio)
        
        # Filtrar solo archivos (ignorar carpetas)
        archivos = [nombre for nombre in nombres if os.path.isfile(os.path.join(directorio, nombre))]

        # Guardar en un archivo de texto
        with open(archivo_salida, 'w', encoding='utf-8') as f:
            for archivo in archivos:
                f.write(archivo + '\n')

        print(f"Se han copiado {len(archivos)} nombres de archivos en '{archivo_salida}'")

    except Exception as e:
        print("Error:", e)

# Ejemplo de uso
ruta = "C:/Users/qjari/curseforge/minecraft/Instances/prueba optifine/mods"
copiar_nombres_archivos(ruta)
