#TEAM RABYTE's code
import matplotlib.pyplot as plt

def oblicz_a(dane_x,dane_y,n):
    licznik=0
    mianownik=0
    suma_xy=0
    suma_x=sum(dane_x)
    suma_y=sum(dane_y)
    suma_xkw=0
    for i in range(n):
        suma_xy+=dane_x[i]*dane_y[i]
        suma_xkw+=dane_x[i]**2
    licznik=(n*suma_xy)-(suma_x*suma_y)
    mianownik=(n*suma_xkw)-(suma_x**2)
    return licznik/mianownik

def main():
    dane_x=[3000,4200,8700,12000]
    dane_y=[25,50,58,120]
    n=len(dane_x)
    a = oblicz_a(dane_x,dane_y,n)
    b = (sum(dane_y)/n)-(a*(sum(dane_x)/n))
    
    print(f'Współczynnik a={round(a,3)}, współczynnik b={round(b,3)}, wykres funkcji liniowej jest postaci y={round(a,3)}x+{round(b,3)}')
    #key=int(input('czy chcesz narysować wykres funkcji regresji? 1-TAK 0-NIE'))

    # wykres rozproszenia:
    plt.scatter(dane_x, dane_y)
    # rysowanie odcinka [xmin, xmax], [ymin, ymax]:
    plt.plot([0, 16000], [b+a*(0), b+a*16000], color="red")

    if 1:
        plt.show() #pokazuje wykres
    else:
        return 0

main()


#wyszlo: 144.37 zl / mies
