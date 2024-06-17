class SaldoEfectivoInsuficiente(Exception):
    pass

class SaldoCuentaInsuficiente(Exception):
    pass

class Cuenta:
    def __init__(self, numero, saldo):
        self.numero = numero
        self.saldo = saldo

class CajeroAutomatico:
    def __init__(self):
        self.cuentas = {}
        self.efectivo_disponible = 100000
    
    def autenticar(self, numero_cuenta):
        return numero_cuenta in self.cuentas
    
    def agregar_cuenta(self, numero_cuenta, saldo_inicial):
        self.cuentas[numero_cuenta] = Cuenta(numero_cuenta, saldo_inicial)
    
    def mostrar_datos_cuenta(self, numero_cuenta):
        cuenta = self.cuentas[numero_cuenta]
        print(f"Cuenta: {cuenta.numero}, Saldo: ${cuenta.saldo:.2f}")
    
    def deposito_propios(self, numero_cuenta, monto):
        cuenta = self.cuentas[numero_cuenta]
        cuenta.saldo += monto
        print(f"Depósito realizado. Nuevo saldo: ${cuenta.saldo:.2f}")
    
    def deposito_otros(self, numero_cuenta_origen, numero_cuenta_destino, monto):
        if numero_cuenta_origen == numero_cuenta_destino:
            print("No puedes depositar a la misma cuenta.")
            return
        
        if numero_cuenta_destino not in self.cuentas:
            print("La cuenta destino no existe.")
            return
        
        cuenta_origen = self.cuentas[numero_cuenta_origen]
        cuenta_destino = self.cuentas[numero_cuenta_destino]
        
        if cuenta_origen.saldo < monto:
            raise SaldoCuentaInsuficiente("Saldo insuficiente para realizar el depósito.")
        
        cuenta_origen.saldo -= monto
        cuenta_destino.saldo += monto
        print(f"Depósito realizado. Nuevo saldo cuenta origen: ${cuenta_origen.saldo:.2f}")
    
    def transferencia(self, numero_cuenta_origen, numero_cuenta_destino, monto):
        self.deposito_otros(numero_cuenta_origen, numero_cuenta_destino, monto)
    
    def retiro(self, numero_cuenta, monto):
        cuenta = self.cuentas[numero_cuenta]
        
        if cuenta.saldo < monto:
            raise SaldoCuentaInsuficiente("Saldo insuficiente para realizar el retiro.")
        
        if self.efectivo_disponible < monto:
            raise SaldoEfectivoInsuficiente("Efectivo insuficiente en el cajero para realizar el retiro.")
        
        cuenta.saldo -= monto
        self.efectivo_disponible -= monto
        print(f"Retiro realizado. Nuevo saldo: ${cuenta.saldo:.2f}, Efectivo disponible en cajero: ${self.efectivo_disponible:.2f}")

def main():
    cajero = CajeroAutomatico()
    
    # Agregar cuentas de prueba
    cajero.agregar_cuenta("1234", 100000)
    cajero.agregar_cuenta("5678", 10000)
    
    while True:
        print("\n--- Cajero Automático ---")
        numero_cuenta = input("Ingrese su número de cuenta (o 'salir' para terminar): ")
        
        if numero_cuenta.lower() == 'salir':
            break
        
        if not cajero.autenticar(numero_cuenta):
            print("Número de cuenta inválido.")
            continue
        
        print("1. Mostrar datos de cuenta y saldo")
        print("2. Depósito en efectivo a cuenta propia")
        print("3. Depósito en efectivo a otras cuentas")
        print("4. Transferencias a otras cuentas")
        print("5. Retiro de efectivo")
        opcion = int(input("Elija una opción: "))
        
        if opcion == 1:
            cajero.mostrar_datos_cuenta(numero_cuenta)
        
        elif opcion == 2:
            monto = float(input("Ingrese el monto a depositar: "))
            cajero.deposito_propios(numero_cuenta, monto)
        
        elif opcion == 3:
            numero_cuenta_destino = input("Ingrese el número de cuenta destino: ")
            monto = float(input("Ingrese el monto a depositar: "))
            try:
                cajero.deposito_otros(numero_cuenta, numero_cuenta_destino, monto)
            except SaldoCuentaInsuficiente as e:
                print(e)
        
        elif opcion == 4:
            numero_cuenta_destino = input("Ingrese el número de cuenta destino: ")
            monto = float(input("Ingrese el monto a transferir: "))
            try:
                cajero.transferencia(numero_cuenta, numero_cuenta_destino, monto)
            except SaldoCuentaInsuficiente as e:
                print(e)
        
        elif opcion == 5:
            monto = float(input("Ingrese el monto a retirar: "))
            try:
                cajero.retiro(numero_cuenta, monto)
            except SaldoCuentaInsuficiente as e:
                print(e)
            except SaldoEfectivoInsuficiente as e:
                print(e)
        
        else:
            print("Opción no válida.")

if __name__ == "__main__":
    main()
