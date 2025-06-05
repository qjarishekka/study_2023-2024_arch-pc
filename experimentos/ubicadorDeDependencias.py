import zipfile
import os

mod_dir = "C:/Users/qjari/curseforge/minecraft/Instances/prueba optifine/mods"  # ← cambia esta ruta por la real en tu PC

for file in os.listdir(mod_dir):
    if file.endswith(".jar"):
        try:
            with zipfile.ZipFile(os.path.join(mod_dir, file), 'r') as jar:
                for name in jar.namelist():
                    if "immediatelyfast" in name.lower():
                        print(f"[FOUND] {file} -> {name}")
                        break
        except zipfile.BadZipFile:
            print(f"[ERROR] {file} no es un .jar válido")
