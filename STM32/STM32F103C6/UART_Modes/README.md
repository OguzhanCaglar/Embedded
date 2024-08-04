# STM32 Mikrodenetleyici ile USART Haberleşme Modları

Bu projede, bir STM32 mikrodenetleyici üzerinde farklı USART haberleşme modları incelenmiştir. Proje, özellikle üç modu kapsamaktadır: polling, interrupt ve DMA.

## UART (Universal Asynchronous Receiver/Transmitter)

UART (Universal Asynchronous Receiver/Transmitter) bir seri haberleşme protokolüdür ve gömülü sistemlerde, bilgisayarlar ve telekomünikasyon cihazları arasında asenkron veri iletişimi için yaygın olarak kullanılır. UART, harici bir saat sinyali gerektirmeden, yani asenkron olarak çalışır; verici (transmitter) ve alıcı (receiver) önceden belirlenmiş bir baud hızında (bit/saniye) ayarlanır ve bu sayede veri bitlerinin ne zaman okunacağını bilir. Veri aktarımı, başlangıç biti, 5 ila 8 bitlik veri, opsiyonel bir parite biti ve en az bir durdurma biti içeren paketler halinde gerçekleşir. UART iletişimi, başlangıç bitiyle başlar, veri bitleri sırasıyla gönderilir ve durdurma bit(leri) ile sonlanır. Bu yöntem, iki cihaz arasında tam çift yönlü iletişim sağlar ve her cihazın TX (transmit) hattı diğer cihazın RX (receive) hattına bağlanır. UART, basit yapısı ve düşük maliyeti nedeniyle birçok gömülü sistemde tercih edilen bir iletişim yöntemidir, ancak veri bütünlüğü için ek kontrol mekanizmalarına ihtiyaç duyabilir ve yüksek hızlı iletişim gerektiren uygulamalar için sınırlamaları vardır.

![UART](images\UART-1.png)

![UART](images\UART-2.png)

## USART (Universal Synchronous Receiver/Transmitter)

USART (Universal Synchronous/Asynchronous Receiver/Transmitter), UART'ın tüm özelliklerini içeren ve ek olarak senkron iletişim modunu da destekleyen bir haberleşme protokolüdür. USART, veri iletişimini hem asenkron (UART gibi) hem de senkron modda gerçekleştirebilir. Asenkron modda, USART, harici bir saat sinyali olmaksızın çalışır ve veri paketlerini başlangıç ve durdurma bitleri ile sınırlayarak iletişim kurar. Buna karşılık, senkron modda USART, veri iletimini senkronize etmek için ek bir saat sinyali kullanır. Bu, veri bitlerinin alıcı ve verici tarafından eş zamanlı olarak okunup yazılmasını sağlar, böylece daha yüksek veri aktarım hızlarına ulaşılabilir. USART’ın bu çift modlu işlevselliği, cihazların farklı iletişim gereksinimlerine esnek bir şekilde uyum sağlamasına olanak tanır. Genellikle, yüksek hız gerektiren uygulamalarda senkron mod tercih edilirken, daha basit ve az hız gerektiren durumlarda asenkron mod kullanılır. USART, mikrodenetleyiciler ve dijital iletişimde yaygın olarak kullanılan bir protokoldür ve UART'a göre daha geniş bir uygulama yelpazesine hitap eder, ancak daha karmaşık donanım gereksinimleri ve konfigürasyonları içerebilir.

![USART](images\USART-1.png)

![USART](images\USART-2.jpg)

## Haberleşme Modları

### Polling Mod

Polling modunda, mikrodenetleyici sürekli olarak USART'tan gelen verileri kontrol eder ve işler. Bu mod nispeten basittir ancak önemli ölçüde işlem gücü tüketebilir.

### Interrupt Mod

Interrupt modunda, veri hazır olduğunda mikrodenetleyiciye USART'tan bir sinyal gönderilir. Bu mod daha verimlidir çünkü mikrodenetleyici, veri gelmesini beklerken diğer görevleri yerine getirebilir.

### DMA Mod

DMA (Direct Memory Access) modunda, mikrodenetleyici, veri transferini CPU müdahalesi olmadan USART ile bellek arasında gerçekleştirebilir. Bu mod, işlem yükünü önemli ölçüde azaltabilir ve sistemin genel performansını artırabilir.

## Uygulama ve Konfigürasyon

Proje, STM32 mikrodenetleyici üzerinde her modun konfigürasyonunu ve uygulamasını HAL (Hardware Abstraction Layer) kütüphanesi kullanarak kapsamaktadır. Ayrıca, her modun kullanımı için STM32 ile Sanal Terminal arasında veri transferine dair pratik örnekler içerir.

## Proteus Devreleri

### Devre Şeması

![Devre](images\Circuit.BMP)

### Çalışan Devre

![Devre-Çalışan](images\Circuit-Working.png)