def get_airspeed_velocity_of(unladen_swallow):
  if unladen_swallow.type == "african":
    return # redacted
  elif unladen_swallow.type == "european":
    return # redacted

def fizzbuzz(num):
<<<<<<< HEAD
  if num % 15 == 0:
    print(f"{num}:fizzbuzz")
  elif num % 3 == 0: # edit this line
    print(f"{num}: fizz")
  elif num % 5 == 0: # edit this line
    print(f"{num}: buzz")
  else: print(f"lalala")
=======
  if num == 3: # edit this line
    print(f"{num}: fizz")
  if num == 5: # edit this line
    print(f"{num}: buzz")
>>>>>>> 53eff2a7a7e0c86848ac8fa2491e484767dec1ba

for i in range(1, 20):
  fizzbuzz(i)
