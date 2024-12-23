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
    EC.element_to_be_clickable((By.CSS_SELECTOR, "[data-test-name='option-arena-plaza-patria']"))
)

# Asegurarse de que el elemento esté visible y hacer clic
driver.execute_script("arguments[0].scrollIntoView(true);", option)
driver.execute_script("arguments[0].click();", option)

# Solicitar al usuario el número de transacción
numero_transaccion = input("Por favor, ingresa el número de transacción (máximo 4 dígitos): ")

# Buscar el campo de entrada e ingresar el número
input_field = driver.find_element(By.ID, "spl_q_arena_feedless_transaccion_txt")
input_field.send_keys(numero_transaccion)

# Avisar al usuario que puede interactuar con la página
print("\nOpción 'Plaza Patria' seleccionada y número de transacción ingresado correctamente.")

# Esperar que el botón "Siguiente" sea clickeable
siguiente_button = WebDriverWait(driver, 15).until(
    EC.element_to_be_clickable((By.ID, "buttonBegin"))
)

# Hacer clic en el botón "Siguiente"
siguiente_button.click()

# Agregar un tiempo de espera explícito para que cargue la nueva página
WebDriverWait(driver, 15).until(
    EC.presence_of_element_located((By.NAME, "onf_q_arena_satisfaccion_general_osat"))
)

# Esperar que el radio button 'Muy Satisfecho' (5) sea clickeable
radio_button = WebDriverWait(driver, 15).until(
    EC.element_to_be_clickable((By.ID, "onf_q_arena_satisfaccion_general_osat_5"))
)

# Hacer clic en el radio button
radio_button.click()

print("Radio button 'Muy Satisfecho' clickeado correctamente.")

# Mantener el script en ejecución
try:
    while True:
        pass  # Mantén el programa corriendo
except KeyboardInterrupt:
    print("\nCerrando el script. Puedes cerrar el navegador manualmente si no lo has hecho.")
