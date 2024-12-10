from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from webdriver_manager.chrome import ChromeDriverManager

# Configuración del navegador
options = Options()

driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)

# URL de la página
url = "https://survey3.medallia.com/arena"
driver.get(url)

# Esperar que el menú esté visible
dropdown = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.CLASS_NAME, "dropdown_dropdownTitle"))
)

# Asegurarse de que el elemento esté visible
driver.execute_script("arguments[0].scrollIntoView(true);", dropdown)

# Usar JavaScript para hacer clic si está bloqueado
driver.execute_script("arguments[0].click();", dropdown)

# Seleccionar la opción 'Plaza Patria' usando `data-test-name`
option = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.CSS_SELECTOR, "[data-test-name='option-arena-plaza-patria']"))
)

# Hacer clic en la opción usando JavaScript
driver.execute_script("arguments[0].scrollIntoView(true);", option)
driver.execute_script("arguments[0].click();", option)

# Solicitar al usuario el número de transacción
numero_transaccion = input("Por favor, ingresa el número de transacción (máximo 4 dígitos): ")

# Buscar el campo de entrada e ingresar el número
input_field = driver.find_element(By.ID, "spl_q_arena_feedless_transaccion_txt")
input_field.send_keys(numero_transaccion)

# Avisar al usuario que puede interactuar con la página
print("\nOpción 'Plaza Patria' seleccionada y número de transacción ingresado correctamente.")

# Esperar que el botón "Siguiente" esté disponible
siguiente_button = WebDriverWait(driver, 15).until(
    EC.presence_of_element_located((By.ID, "buttonBegin"))
)

# Hacer clic en el botón "Siguiente" usando JavaScript
driver.execute_script("arguments[0].scrollIntoView(true);", siguiente_button)
driver.execute_script("arguments[0].click();", siguiente_button)

# Esperar a que cargue la nueva página
WebDriverWait(driver, 15).until(
    EC.presence_of_element_located((By.ID, "onf_q_arena_satisfaccion_general_osat_5"))
)

# Buscar el radio button 'Muy Satisfecho' (5)
radio_button = driver.find_element(By.ID, "onf_q_arena_satisfaccion_general_osat_5")

# Hacer clic en el radio button usando JavaScript
driver.execute_script("arguments[0].scrollIntoView(true);", radio_button)
driver.execute_script("arguments[0].click();", radio_button)

print("Radio button 'Muy Satisfecho' clickeado correctamente.")

# Mantener el navegador abierto para que el usuario pueda continuar
try:
    print("\nNavegador listo para interactuar. Presiona Ctrl + C para cerrar el script.")
    while True:
        pass  # Mantén el programa corriendo
except KeyboardInterrupt:
    print("\nCerrando el script. Puedes cerrar el navegador manualmente si no lo has hecho.")