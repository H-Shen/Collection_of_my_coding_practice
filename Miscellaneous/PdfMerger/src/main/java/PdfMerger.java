import com.itextpdf.text.Document;
import com.itextpdf.text.DocumentException;
import com.itextpdf.text.pdf.PdfCopy;
import com.itextpdf.text.pdf.PdfImportedPage;
import com.itextpdf.text.pdf.PdfReader;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;

/**
 * @author hshen
 */
public class PdfMerger {

    public static final int MINIMAL_ARGS = 3;

    public static void mergePdf(String[] pdfList, String filename) {
        Document         document         = null;
        PdfCopy          pdfCopy          = null;
        FileOutputStream fileOutputStream = null;
        try {
            document = new Document(new PdfReader(new FileInputStream(pdfList[0])).getPageSize(1));
            fileOutputStream = new FileOutputStream(filename);
            pdfCopy = new PdfCopy(document, fileOutputStream);
            document.open();
            for (String s : pdfList) {
                System.out.println("Merging " + s + " ...");
                PdfReader pdfReader = new PdfReader(new FileInputStream(s));
                int       n         = pdfReader.getNumberOfPages();
                for (int j = 0; j < n; ++j) {
                    document.newPage();
                    PdfImportedPage pdfImportedPage = pdfCopy.getImportedPage(pdfReader, j + 1);
                    pdfCopy.addPage(pdfImportedPage);
                }
                pdfReader.close();
            }
        } catch (IOException | DocumentException e) {
            e.printStackTrace();
        } finally {
            if (pdfCopy != null) {
                pdfCopy.close();
            }
            if (fileOutputStream != null) {
                try {
                    fileOutputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (document != null) {
                document.close();
            }
        }
    }

    public static boolean isPdf(byte[] data) {
        return data != null && data.length > 4 &&
                // %PDF-
                data[0] == 0x25 &&
                data[1] == 0x50 &&
                data[2] == 0x44 &&
                data[3] == 0x46 &&
                data[4] == 0x2D;
    }

    public static boolean argsCheck(String[] args) {
        // Check if the length is at least 3
        if (args.length < MINIMAL_ARGS) {
            return false;
        }
        File f;
        // For all files to be merged, we check if they are all valid pdf files
        try {
            for (int i = 0; i < args.length - 1; ++i) {
                f = new File(args[i]);
                if (!f.exists()) {
                    return false;
                }
                if (f.isDirectory() || !PdfMerger.isPdf(Files.readAllBytes(Paths.get(args[i])))) {
                    return false;
                }
            }
        } catch (IOException e) {
            return false;
        }
        // Check if the output is a directory
        f = new File(args[args.length - 1]);
        return !f.isDirectory();
    }

    public static void main(String[] args) {
        if (!argsCheck(args)) {
            System.out.println("Usage:\njava -jar target/PdfMerger-0.0.1.jar [Paths for all pdfs need to be merged] " +
                    "[file " +
                    "path for the " +
                    "merged pdf]");
            System.out.println("Example:\njava -jar target/PdfMerger-0.0.1.jar input0.pdf input1.pdf output.pdf");
        } else {
            mergePdf(Arrays.copyOfRange(args, 0, args.length - 1), args[args.length - 1]);
            System.out.println("Done");
        }
    }
}
