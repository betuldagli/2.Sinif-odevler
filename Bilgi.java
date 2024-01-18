import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Bilgi {
    static Kargo[] hashTablo = new Kargo[10];
    static int hashIndex2 = 7;
    public static void main(String[] args) {
        Scanner giris = new Scanner(System.in);
        int secim;
        int kontrol=1;

        while (kontrol == 1) {
            System.out.print("0-Texten veri girişi yap.\n1-Tüm kargoları listele.\n2-Kargo girişi.\n3-Kargo takip.\n4-Kargoyu teslim et.\n5-Çıkış\nİşlem giriniz:");
            secim = giris.nextInt();

            switch (secim) {
                case 0:
                    dosyayiOku();
                    break;
                case 1:
                    yazdir();
                    break;
                case 2:
                    dosyayaEkle();
                    break;
                case 3:
                    adimBul();
                    break;
                case 4:
                    kargoTeslim();
                    break;
                case 5:
                    kontrol = 0;
                    break;
                default:
                    System.out.println("Geçerli işlem giriniz:");
            }
        }

    }

    public static void yazdir() {
        System.out.println("Takip No\t " + "Gönderici\t" + "Alıcı\t" + "Kargo Durumu\t");
        for (int i = 0; i < hashTablo.length; i++) {
            if (hashTablo[i] != null) {
                System.out.println(hashTablo[i].takipNo + "\t\t\t" +
                        hashTablo[i].gonderici + "\t\t" +
                        hashTablo[i].alici + "\t\t" +
                        hashTablo[i].kargoDurum);
            }
        }
    }

    public static void dosyayaEkle() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\Users\\Betül DAĞLI\\Desktop\\veri.txt", true))) {
            Scanner giris = new Scanner(System.in);

            String takipNo;
            String gonderici;
            String alici;
            String kargoDurum;

            System.out.println("Takip No:");
            takipNo = giris.nextLine();
            System.out.println("Gönderici:");
            gonderici = giris.nextLine();
            System.out.println("Alıcı:");
            alici = giris.nextLine();
            System.out.println("Kargo durumu:");
            kargoDurum = giris.nextLine();

            Kargo yeniKargo = new Kargo(takipNo, gonderici, alici, kargoDurum);

            writer.write("\n" + takipNo + "\t" + gonderici + "\t" + alici + "\t" + kargoDurum);
            writer.flush();

            System.out.println("Yeni kargo eklendi.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void dosyayiOku() {
        try (BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\Betül DAĞLI\\Desktop\\veri.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("\t");
                if (parts.length < 4) {
                    System.out.println("Hatalı satır: " + line);
                    continue;
                }
                String takipNo = parts[0];
                String gonderici = parts[1];
                String alici = parts[2];
                String kargoDurum = parts[3];
                int hashIndex1 = Integer.parseInt(takipNo) % 10;
                int deneme = 0;
                int hashIndex = (hashIndex1 + deneme * hashIndex2) % 10;

                while (hashTablo[hashIndex] != null && deneme < 10) {
                    if(takipNo.equals(hashTablo[hashIndex].takipNo)){
                    //System.out.println("Aynı takip nolu kargo var.");
                    break;
                }
                    deneme++;
                    hashIndex = (hashIndex1 + deneme * hashIndex2) % 10;
                }


                if (hashTablo[hashIndex] == null) {
                    hashTablo[hashIndex] = new Kargo(takipNo, gonderici, alici, kargoDurum);
                    System.out.println(takipNo+":"+hashIndex+". indekse eklendi.");
                }
                if(hashTablo.length==deneme) {
                    System.out.println("Tablo dolu! Takip No: " + takipNo + " eklenemedi.");
                }
            }
            System.out.println("Veriler başarıyla kaydedildi.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void adimBul(){
        Scanner giris = new Scanner(System.in);
        String takipNo;
        int sayac = 0;

        System.out.println("Aradığınız kargonun takip numarasını giriniz:");
        System.out.println("Takip No:");
        takipNo = giris.nextLine();

        int i;
        for (i = 0; i < hashTablo.length; i++) {
            if (hashTablo[i] == null) {
                continue;
            }

            sayac++;
            if (takipNo.equals(hashTablo[i].takipNo)) {
                break;
            }
        }

        if (i == hashTablo.length) {
            System.out.println("Kargo bulunamadı.");
        } else {
            System.out.println((sayac) + " Adımda bulundu.");
            System.out.println(hashTablo[sayac].takipNo+"\t"+hashTablo[sayac].gonderici+"\t"+hashTablo[sayac].alici+"\t"+hashTablo[sayac].kargoDurum);
        }
    }
    public static void kargoTeslim(){
        Scanner giris = new Scanner(System.in);
        String takipNo;


        System.out.println("Teslim edilen kargonun takip numarasını giriniz:");
        System.out.println("Takip No:");
        takipNo = giris.nextLine();

        int i;
        for (i = 0; i < hashTablo.length; i++) {
            if (hashTablo[i] == null) {
                continue;
            }
            if (takipNo.equals(hashTablo[i].takipNo)) {
                System.out.println("Kargo teslim edildi.");
                hashTablo[i]=null;
                break;
            }
            if(i==hashTablo.length-1){
                System.out.println("Kargo bulunamadı.");
            }
        }
      }
    }