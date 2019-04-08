package PBL;

import java.awt.Color;
import java.awt.Cursor;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

class MenuFrame extends JFrame {
	MenuPanel mf = new MenuPanel();

	private Image screenImage;
	private Graphics screenGraphic;

	private ImageIcon exitButtonEnteredImage = new ImageIcon(
			PBL.class.getResource("../image_cafe/exitButtonEntered.png"));
	private ImageIcon exitButtonBasicImage = new ImageIcon(PBL.class.getResource("../image_cafe/exitButtonBasic.png"));
	private ImageIcon allwindowButtonEnteredImage = new ImageIcon(
			PBL.class.getResource("../image_cafe/allwindowButtonEntered.png"));
	private ImageIcon allwindowButtonBasicImage = new ImageIcon(
			PBL.class.getResource("../image_cafe/allwindowButtonBasic.png"));
	private ImageIcon underbarButtonEnteredImage = new ImageIcon(
			PBL.class.getResource("../image_cafe/underbarButtonEntered.png"));
	private ImageIcon underbarButtonBasicImage = new ImageIcon(
			PBL.class.getResource("../image_cafe/underbarButtonBasic.png"));
	private ImageIcon backButtonEnteredImage = new ImageIcon(
			PBL.class.getResource("../image_cafe/backButtonEntered.png"));
	private ImageIcon backButtonBasicImage = new ImageIcon(PBL.class.getResource("../image_cafe/backButtonBasic.png"));

	private Image backgroundMenuFrame = new ImageIcon(
			PBL.class.getResource("../image_cafe/menuFrameBackGround(Title).jpg")).getImage();
	private JLabel menuBar = new JLabel(new ImageIcon(PBL.class.getResource("../image_cafe/menuBar2.png")));

	private JButton exitButton = new JButton(exitButtonBasicImage);
	private JButton allwindowButton = new JButton(allwindowButtonBasicImage);
	private JButton underbarButton = new JButton(underbarButtonBasicImage);
	private JButton backButton = new JButton(backButtonBasicImage);

	private int mouseX, mouseY;

	MenuFrame() {
		setUndecorated(true);
		setTitle("Cafe's POS");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(mf);

		setSize(PBL.SCREEN_WIDTH, PBL.SCREEN_LENGTH);
		setResizable(false);
		setLocationRelativeTo(null);
		setVisible(true);
		setBackground(new Color(0, 0, 0, 0));

		exitButton.setBounds(442, 4, 53, 22);
		exitButton.setBorderPainted(false);
		exitButton.setContentAreaFilled(false);
		exitButton.setFocusable(false);
		exitButton.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				exitButton.setIcon(exitButtonEnteredImage);
				exitButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
			}

			public void mouseExited(MouseEvent e) {
				exitButton.setIcon(exitButtonBasicImage);
				exitButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}

			public void mousePressed(MouseEvent e) {
				CafeMusic buttonEnteredMusic = new CafeMusic("buttonMusic.mp3", false);
				buttonEnteredMusic.start();
				try {
					Thread.sleep(500);
				} catch (InterruptedException ex) {
					ex.printStackTrace();
				}
				System.exit(0);
			}
		});
		add(exitButton);

		allwindowButton.setBounds(412, 4, 33, 22);
		allwindowButton.setBorderPainted(false);
		allwindowButton.setContentAreaFilled(false);
		allwindowButton.setFocusable(false);
		allwindowButton.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				allwindowButton.setIcon(allwindowButtonEnteredImage);
				allwindowButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
			}

			public void mouseExited(MouseEvent e) {
				allwindowButton.setIcon(allwindowButtonBasicImage);
				allwindowButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}

			public void mousePressed(MouseEvent e) {
				CafeMusic buttonEnteredMusic = new CafeMusic("buttonMusic.mp3", false);
				buttonEnteredMusic.start();
			}
		});
		add(allwindowButton);

		underbarButton.setBounds(383, 4, 33, 22);
		underbarButton.setBorderPainted(false);
		underbarButton.setContentAreaFilled(false);
		underbarButton.setFocusable(false);
		underbarButton.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				underbarButton.setIcon(underbarButtonEnteredImage);
				underbarButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
			}

			public void mouseExited(MouseEvent e) {
				underbarButton.setIcon(underbarButtonBasicImage);
				underbarButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}

			public void mousePressed(MouseEvent e) {
				CafeMusic buttonEnteredMusic = new CafeMusic("buttonMusic.mp3", false);
				buttonEnteredMusic.start();
				setExtendedState(JFrame.ICONIFIED);
			}
		});
		add(underbarButton);

		backButton.setBounds(4, 4, 32, 22);
		backButton.setBorderPainted(false);
		backButton.setContentAreaFilled(false);
		backButton.setFocusable(false);
		backButton.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				backButton.setIcon(backButtonEnteredImage);
				backButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
			}

			public void mouseExited(MouseEvent e) {
				backButton.setIcon(backButtonBasicImage);
				backButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}

			public void mousePressed(MouseEvent e) {
				CafeMusic buttonEnteredMusic = new CafeMusic("buttonMusic.mp3", false);
				buttonEnteredMusic.start();
				PBL.orderNumber = 1;
				dispose();
				new OpenFrame();
			}
		});
		add(backButton);

		menuBar.setBounds(0, 0, 500, 30);
		menuBar.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				mouseX = e.getX();
				mouseY = e.getY();
			}
		});
		menuBar.addMouseMotionListener(new MouseMotionAdapter() {
			public void mouseDragged(MouseEvent e) {
				int x = e.getXOnScreen();
				int y = e.getYOnScreen();
				setLocation(x - mouseX, y - mouseY);
			}
		});
		add(menuBar);
	}

	public void paint(Graphics g) {
		screenImage = createImage(PBL.SCREEN_WIDTH, PBL.SCREEN_LENGTH);
		screenGraphic = screenImage.getGraphics();
		screenDraw(screenGraphic);
		g.drawImage(screenImage, 0, 0, null);
	}

	public void screenDraw(Graphics g) {
		g.drawImage(backgroundMenuFrame, 0, 0, null);

		paintComponents(g);
		this.repaint();
	}

	class MenuPanel extends JPanel {
		JButton �ֹ�, ����, ����, ����;

		MenuPanel() {
			setLayout(null);
			�ֹ� = new JButton("�ֹ�");
			�ֹ�.setBounds(250, 170, 150, 60);
			add(�ֹ�);
			�ֹ�.addMouseListener(new MouseAdapter() {
				public void mouseEntered(MouseEvent e) {
					�ֹ�.setCursor(new Cursor(Cursor.HAND_CURSOR));
				}

				public void mouseExited(MouseEvent e) {
					�ֹ�.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
				}

				public void mousePressed(MouseEvent e) {
					CafeMusic buttonEnteredMusic = new CafeMusic("buttonMusic.mp3", false);
					buttonEnteredMusic.start();
					dispose();
					new CafeMenuFrame();
				}
			});

			���� = new JButton("����");
			����.setBounds(250, 240, 150, 60);
			add(����);
			����.addMouseListener(new MouseAdapter() {
				public void mouseEntered(MouseEvent e) {
					����.setCursor(new Cursor(Cursor.HAND_CURSOR));
				}

				public void mouseExited(MouseEvent e) {
					����.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
				}

				public void mousePressed(MouseEvent e) {
					CafeMusic buttonEnteredMusic = new CafeMusic("buttonMusic.mp3", false);
					buttonEnteredMusic.start();
					dispose();
					new CalculateFrame();
				}
			});

			���� = new JButton("����");
			����.setBounds(250, 310, 150, 60);
			add(����);
			����.addMouseListener(new MouseAdapter() {
				public void mouseEntered(MouseEvent e) {
					����.setCursor(new Cursor(Cursor.HAND_CURSOR));
				}

				public void mouseExited(MouseEvent e) {
					����.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
				}

				public void mousePressed(MouseEvent e) {
					CafeMusic buttonEnteredMusic = new CafeMusic("buttonMusic.mp3", false);
					buttonEnteredMusic.start();
					File check = new File("C:\\Java Cafe");
					File dst = new File("C:\\Java Cafe\\" + PBL.year + "." + PBL.month + "." + PBL.day + ".txt");
					FileOutputStream fo;
					OutputStreamWriter out;

					String newLine = System.getProperty("line.separator");
					try {
						fo = new FileOutputStream(dst);
						out = new OutputStreamWriter(fo);
						out.write("--------------------------------------------��" + newLine);
						out.write("�Ƹ޸�ī�� �Ǹ� �Ǽ� : " + PBL.totalAmericano + " �ǡ�" + newLine);
						out.write("������ �Ǹ� �Ǽ� : " + PBL.totalFrappe + " �ǡ�" + newLine);
						out.write("ī��� �Ǹ� �Ǽ� : " + PBL.totalCafeLatte + " �ǡ�" + newLine);
						out.write("īǪġ�� �Ǹ� �Ǽ� : " + PBL.totalCapuccino + " �ǡ�" + newLine);
						out.write("�ͽ������� �Ǹ� �Ǽ� : " + PBL.totalExpress + " �ǡ�" + newLine);
						out.write("���̽�Ƽ �Ǹ� �Ǽ� : " + PBL.totalIceTea + " �ǡ�" + newLine);
						out.write("�����̵� �Ǹ� �Ǽ� : " + PBL.totalLemonAdes + " �ǡ�" + newLine);
						out.write("��ũƼ �Ǹ� �Ǽ� : " + PBL.totalMilkTea + " �ǡ�" + newLine);
						out.write("�������� �Ǹ� �Ǽ� : " + PBL.totalAffogato + " �ǡ�" + newLine);
						out.write("--------------------------------------------��" + newLine);
						out.write("ī�� ��� : " + PBL.cardselln + " �ǡ�" + newLine);
						out.write("���� ��� : " + PBL.moneyselln + " �ǡ�" + newLine);
						out.write("���ͱ� : " + PBL.money + " ����" + newLine);
						out.close();
						fo.close();

					} catch (IOException a) {
						if (!check.exists()) {
							check.mkdir();
						}
						try {
							fo = new FileOutputStream(dst);
							out = new OutputStreamWriter(fo);
							out.write("--------------------------------------------��" + newLine);
							out.write("�Ƹ޸�ī�� �Ǹ� �Ǽ� : " + PBL.totalAmericano + " �ǡ�" + newLine);
							out.write("������ �Ǹ� �Ǽ� : " + PBL.totalFrappe + " �ǡ�" + newLine);
							out.write("ī��� �Ǹ� �Ǽ� : " + PBL.totalCafeLatte + " �ǡ�" + newLine);
							out.write("īǪġ�� �Ǹ� �Ǽ� : " + PBL.totalCapuccino + " �ǡ�" + newLine);
							out.write("�ͽ������� �Ǹ� �Ǽ� : " + PBL.totalExpress + " �ǡ�" + newLine);
							out.write("���̽�Ƽ �Ǹ� �Ǽ� : " + PBL.totalIceTea + " �ǡ�" + newLine);
							out.write("�����̵� �Ǹ� �Ǽ� : " + PBL.totalLemonAdes + " �ǡ�" + newLine);
							out.write("��ũƼ �Ǹ� �Ǽ� : " + PBL.totalMilkTea + " �ǡ�" + newLine);
							out.write("�������� �Ǹ� �Ǽ� : " + PBL.totalAffogato + " �ǡ�" + newLine);
							out.write("--------------------------------------------��" + newLine);
							out.write("ī�� ��� : " + PBL.cardselln + " �ǡ�" + newLine);
							out.write("���� ��� : " + PBL.moneyselln + " �ǡ�" + newLine);
							out.write("���ͱ� : " + PBL.money + " ����" + newLine);
							out.close();
							fo.close();
						} catch (IOException k) {
							System.out.println(k.getMessage());
						}
					}
					dispose();
					new DeadLineFrame();
				}
			});

			���� = new JButton("����");
			����.setBounds(250, 380, 150, 60);
			add(����);
			����.addMouseListener(new MouseAdapter() {
				public void mouseEntered(MouseEvent e) {
					����.setCursor(new Cursor(Cursor.HAND_CURSOR));
				}

				public void mouseExited(MouseEvent e) {
					����.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
				}

				public void mousePressed(MouseEvent e) {
					CafeMusic buttonEnteredMusic = new CafeMusic("buttonMusic.mp3", false);
					buttonEnteredMusic.start();
					try {
						Thread.sleep(500);
					} catch (InterruptedException ex) {
						ex.printStackTrace();
					}
					System.exit(0);
				}
			});
		}
	}
}
