Bu projede, C++ programlama dili kullanılarak, karmaşık sayılar uzayında tanımlı olan vektör 
ve matris üzerinde bir takım lineer cebir işlemleri gerçekleştiren sınıf ve metotları 
gerçeklemeniz ve main metodu içerisinde test etmeniz beklenmektedir.  
Tanım: z = a + bi karmaşık sayısında a ya karmaşık sayının reel (gerçel) kısmı, b ye karmaşık 
sayını imajiner (sanal) kısmı denir ve Re(z) = a, İm(z) = b şeklinde gösterilir. 
Gerçeklenmesi gereken sınıflar ve ilgili metotları aşağıda verilmiştir: 

1. “Imaginary” adında, üye değişkeni (niteliği) ‘private’ olan bir sınıf gerçekleyin. Bu 
sınıf karmaşık sayıların sanal (Imaginary) kısmını ifade edecektir.

2. Karmaşık sayıları temsil etmek için “Imaginary” sınıfından türettiğiniz (inheritance), 
“Complex” adında bir sınıf gerçekleyin. Üye değişkenleri, gerçel “re” ve sanal “im”, ve 
kısımları “private” olmalıdır.  
a. Bu sınıf üzerinde toplama (+), çıkarma (-), bölme (/), çarpma (*), eşlenik(~), 
atama (=), toplama atama (+=), çıkarma atama (-=), çarpma atama (*=), bölme atama 
(/=) ve eşit mi(==) gibi aritmetik ve lojik işlemler aşırı yüklenecektir.

3. Complex sayılar üzerinde tanımlı, “Vector” ve “Matrix” adında sınıfları gerçekleyin. 
“Vector” sınıfının ‘size_t’ tipinden “size” adında ve “Complex” tipinden “element” adında 
özellikleri ‘private’ olmalıdır. “Matrix” sınıflara ait ‘size_t’ tipinden “row”, “col” ve 
“Complex” tipinden “element” adında nitelikleri ‘private’ olmalıdır. Bu sınıflar üzerinde 
“Complex” sınıfındaki gibi aşağıdaki operatörler aşırı yüklenecektir:

+(Toplama): operator+ 
Matrix/Vector nesnesini elemanlarını toplayan operatör

 -(Çıkarma): operator-
Matrix/Vector nesnesini elemanlarını çıkaran operatör

 *(Çarpma): operator* 
Eğer Vector nesnesi ise iç çarpım (dot product), Matrix nesnesi ise matris çarpımı gerçekleştiren operatör

= (Atama): operator= 
Bir Matrix/Vector nesnesini başka bir Matrix/Vector nesnesine atayan operatör 

+= (Toplama atama): operator+= 
Matrix/Vector nesnesini elemanlarını toplayıp atama yapan operatör

-= (Çıkarma atama): operator-= 
Matrix/Vector nesnesini elemanlarını çıkarıp atama yapan operatör 

*= (Çarpma atama): operator*= 
Eğer Vector nesnesi ise iç çarpım (dot product), Matrix nesnesi ise matris çarpımı gerçekleştiren operatör (bu işlem ancak matrisler kare ise gerçekleştirilebilir) 

== (Eşitlik): operator== 
İki Matrix/Vector nesnelerinin eşit olup olmadıklarını kontrol eden operatör

 a. “Matrix” sınıfının, matrisin transpozunu hesaplayan “transpose” ve determinantı 
hesaplayan “determinant” metotlarını gerçekleyin.

4. “Matrix” sınıfından türetilecek “SquareMatrix”, “IdentityMatrix” ve “TriangleMatrix” 
sınıflarını gerçekleyin.

5. Son olarak, “LinearAlgebraObject” adında soyut (abstract) sınıf gerçekleyin. Bu sınıf, 
lineer cebir nesnelerinin (örneğin, Vector, Matrix, SquareMatrix, IdentityMatrix, 
TriangleMatrix) ortak davranışlarını tanımlamak için kullanılacaktır.

Her sınıfa ait “print()”, kurucu (constructor), kopyalama kurucularını (copy constructor) ve 
gerekli tüm metotlar gerektiği kadar gerçeklenmelidir. 
